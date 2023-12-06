#include "parser/logo_parser.h"

#include "keys.h"

Parser::Parser(std::string file_contents) {
  this->data = std::stringstream(file_contents);
}

bool Parser::HasNext() const { return !data.eof(); }

void Parser::Next() {
  getline(data, buf);
  std::string command_str;
  std::string magnitude_str;
  if (buf.find(' ') == std::string::npos) {
    command_str = buf;
    magnitude = 0;
  } else {
    command_str = buf.substr(0, buf.find(' '));
    magnitude_str = buf.substr(buf.find(' ') + 1, buf.back());
    this->magnitude = stoi(magnitude_str);
  }
  std::map<std::string, int> command_map;
  command_map["fd"] = KEY_UP;
  command_map["bk"] = KEY_DOWN;
  command_map["lt"] = KEY_LEFT;
  command_map["rt"] = KEY_RIGHT;
  command_map["pu"] = KEY_SPACE;
  command_map["pd"] = KEY_SPACE;
  command_map["pc"] = KEY_PRINT;

  command = command_map[command_str];
}

int Parser::GetCommand() const { return command; }
int Parser::GetMagnitude() const { return magnitude; }
