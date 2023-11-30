#include "parser/logo_repeat_handler.h"

constexpr std::string_view repeat_command = "repeat";

void trim(std::string &string) {
  string.erase(string.begin(),
               std::find_if(string.begin(), string.end(),
                            std::bind_front(std::not_equal_to<char>(), ' ')));
}

std::string remove_loop(const std::string &string) {
  std::string out = string.substr(string.find("[") + 1,
                                  string.length() - (string.find("[") + 1) - 1);
  trim(out);
  return out;
}

std::stringstream LogoRepeatHandler::handle(std::stringstream &ss) const {
  std::stringstream out;
  for (std::string line; std::getline(ss, line);) {
    size_t f = line.find(repeat_command);
    if (f != std::string::npos) {
      line.erase(f, repeat_command.length());
      trim(line);
      // Get the number of times to repeat
      int number_of_repeats = std::stoi(line.substr(0, line.find(" ")));
      for (int i = 0; i < number_of_repeats; i++) {
        // Get the line to repeat
        std::string line_to_repeat = remove_loop(line);
        // Add the line to repeat to the stringstream
        out << line_to_repeat << std::endl;
      }
    } else {
      out << line << std::endl;
    }
  }
  return out;
}
