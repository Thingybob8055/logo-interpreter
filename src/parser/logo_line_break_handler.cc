#include "parser/logo_line_break_handler.h"

const std::vector<std::string> list_of_commands_with_magnitude = {"fd", "bk",
                                                                  "lt", "rt"};

struct {
  std::string open_bracket = "[";
  std::string close_bracket = "]";
  std::string repeat_word = "repeat";
} r;

bool is_number(const std::string &s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

void add_to_buffer(std::stringstream &buf, std::string &s) {
  if (s == r.close_bracket)
    buf << s;
  else
    buf << s << " ";
}

void reset_values(std::stringstream &buf, int &lvalue, int &rvalue,
                  bool &repeat) {
  lvalue = 0;
  rvalue = 0;
  buf.clear();
  repeat = false;
}

void get_nested_repeat(std::string &line, std::string &s,
                       std::vector<std::string> &split_line,
                       std::stringstream &buf) {
  std::stringstream ss(line);
  int lvalue = 0, rvalue = 0;
  bool repeat = false;
  while (std::getline(ss, s, ' ')) {
    if (s == r.repeat_word) {
      repeat = true;
      add_to_buffer(buf, s);
      continue;
    }
    if (repeat) {
      if (is_number(s)) {
        add_to_buffer(buf, s);
        continue;
      } else if (s == r.open_bracket) {
        lvalue++;
        add_to_buffer(buf, s);
      } else if (s == r.close_bracket) {
        rvalue++;
        add_to_buffer(buf, s);
        if (lvalue == rvalue) {
          split_line.push_back(buf.str());
          reset_values(buf, lvalue, rvalue, repeat);
        }
      } else {
        add_to_buffer(buf, s);
      }
    } else {
      if (s == r.close_bracket || s == r.open_bracket) {
        std::cerr << "Fatal error while parsing." << std::endl;
        exit(1);
      }
      split_line.push_back(s);
    }
  }
}

std::vector<std::string> line_to_vector(std::string &line) {
  std::string s;
  std::vector<std::string> split_line;
  std::stringstream buf;

  get_nested_repeat(line, s, split_line, buf);

  return split_line;
}

bool has_magnitude(std::string command) {
  return std::find(list_of_commands_with_magnitude.begin(),
                   list_of_commands_with_magnitude.end(),
                   command) != list_of_commands_with_magnitude.end();
}

void format_to_stream(std::vector<std::string> &split_line,
                      std::stringstream &out) {
  for (int i = 0; i < split_line.size(); i++) {
    std::string current_item = split_line[i];
    if (has_magnitude(current_item)) {
      std::string next_item = split_line[i + 1];
      out << current_item << " " << next_item << std::endl;
      i++;
    } else {
      out << current_item << std::endl;
    }
  }
}

std::stringstream LogoLineBreakHandler::Handle(std::stringstream &ss) const {
  std::stringstream out;
  for (std::string line; std::getline(ss, line);) {
    std::vector<std::string> split_line = line_to_vector(line);
    format_to_stream(split_line, out);
  }
  return out;
}
