#include "parser/logo_repeat_handler.h"

constexpr std::string_view repeat_command = "repeat";

void trim(std::string &string) {
  string.erase(string.begin(),
               std::find_if(string.begin(), string.end(),
                            std::bind_front(std::not_equal_to<char>(), ' ')));
}

std::string remove_loop_brackets(const std::string &string) {
  std::string out = string.substr(string.find("[") + 1,
                                  string.length() - (string.find("[") + 1) - 1);
  trim(out);
  return out;
}

void erase_repeat_command(size_t repeat_location, std::string &line) {
  line.erase(repeat_location, repeat_command.length());
  trim(line);

}

void expand_repeat(std::string &line, std::stringstream &out) {
  int number_of_iterations = std::stoi(line.substr(0, line.find(" ")));
      for (int i = 0; i < number_of_iterations; i++) {
        std::string line_to_repeat = remove_loop_brackets(line);
        out << line_to_repeat << std::endl;
      }
}

std::stringstream LogoRepeatHandler::handle(std::stringstream &ss) const {
  std::stringstream out;
  for (std::string line; std::getline(ss, line);) {
    size_t repeat_location = line.find(repeat_command);
    if (repeat_location != std::string::npos) {
      erase_repeat_command(repeat_location, line);
      expand_repeat(line, out);
    } else {
      out << line << std::endl;
    }
  }
  return out;
}
