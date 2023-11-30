#include "parser/logo_line_break_handler.h"

#include <iostream>
#include <vector>

const std::vector<std::string> list_of_commands_with_magnitude = {"fd", "bk",
                                                                  "lt", "rt"};

std::stringstream LogoLineBreakHandler::handle(std::stringstream &ss) const {
  std::stringstream out;

  // TODO: Loop through each line in the stringstream
  for (std::string line; std::getline(ss, line);) {
    // TODO: Break up line by spaces and loop through each word
    std::string s;
    std::stringstream ss(line);
    std::vector<std::string> v;

    while (std::getline(ss, s, ' ')) {
      v.push_back(s);
    }

    // print the vector
    for (int i = 0; i < v.size(); i++) {
      if (std::find(list_of_commands_with_magnitude.begin(),
                    list_of_commands_with_magnitude.end(),
                    v[i]) != list_of_commands_with_magnitude.end()) {
        // TODO: If word is a command with a magnitude, add a line break after
        // the next word std::cout << v[i] << " Is a command w/magnitude!" <<
        // std::endl;
        out << v[i] << " " << v[i + 1] << std::endl;
        i++;
      } else {
        // TODO: If word is a command without a magnitude, add a line break
        // after current word std::cout << v[i] << std::endl;
        out << v[i] << std::endl;
      }
    }
  }

  return out;
}
