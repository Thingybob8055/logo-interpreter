#include "parser/logo_line_break_handler.h"

const std::vector<std::string> list_of_commands_with_magnitude = {"fd", "bk",
                                                                  "lt", "rt"};

std::vector<std::string> line_to_vector(std::string &line) {
  std::string s;
  std::stringstream ss(line);
  std::vector<std::string> split_line;
  while (std::getline(ss, s, ' ')) {
   split_line.push_back(s);
  }
  return split_line;
}

bool has_magnitude(std::string command) {
  return std::find(list_of_commands_with_magnitude.begin(),
                    list_of_commands_with_magnitude.end(),
                    command) != list_of_commands_with_magnitude.end();
}

void format_to_stream(std::vector<std::string> &split_line, std::stringstream &out) {
  for (int i = 0; i < split_line.size(); i++) {
    std::string current_item = split_line[i];
    if (has_magnitude(current_item)) {
      std::string next_item = split_line[i+1];
      out << current_item << " " << next_item << std::endl;
      i++;
    } else {
      out << current_item << std::endl;
    }
  }
}

std::stringstream LogoLineBreakHandler::handle(std::stringstream &ss) const {
  std::stringstream out;
  for (std::string line; std::getline(ss, line);) {
    std::vector<std::string> split_line = line_to_vector(line);
    format_to_stream(split_line, out);
  }
  return out;
}
