#include "parser/logo_parser.h"

Parser::Parser(std::string fileContents) {
  this->data = std::stringstream(fileContents);
}

void Parser::Next() {
  getline(data, buf);
  std::string commandStr;
  std::string magnitudeStr;
  if (buf.find(' ') == std::string::npos) {
    commandStr = buf;
    magnitude = 0;
  } else {
    commandStr = buf.substr(0, buf.find(' '));
    magnitudeStr = buf.substr(buf.find(' ') + 1, buf.back());
    this->magnitude = stoi(magnitudeStr);
  }
  std::map<std::string, int> commandMap;
  commandMap["fd"] = KEY_UP;
  commandMap["bk"] = KEY_DOWN;
  commandMap["lt"] = KEY_LEFT;
  commandMap["rt"] = KEY_RIGHT;
  // not yet implemented in renderer
  // commandMap["cs"];
  // commandMap["ht"];
  // commandMap["st"];
  // only implemented as toggle instead of seperate commands
  // commandMap["pu"];
  // commandMap["pd"];

  command = commandMap[commandStr];
}

int Parser::GetCommand() { return command; }
int Parser::GetMagnitude() { return magnitude; }
