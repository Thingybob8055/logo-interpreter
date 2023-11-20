#ifndef LOGO_PARSER_H_
#define LOGO_PARSER_H_

#include <curses.h>
#include <string.h>

#include <iostream>
#include <map>
#include <sstream>

constexpr int KEY_SPACE = 32;

class Parser {
 private:
  std::stringstream data;
  std::string buf;
  int command;
  int magnitude;

 public:
  explicit Parser(std::string file_contents);

  bool HasNext() const;
  void Next();
  int GetCommand() const;
  int GetMagnitude() const;
};

#endif