#ifndef LOGO_PARSER_H_
#define LOGO_PARSER_H_

#define KEY_SPACE 32

#include <curses.h>
#include <string.h>

#include <iostream>
#include <map>
#include <sstream>

class Parser {
 private:
  std::stringstream data;
  std::string buf;
  int command;
  int magnitude;

 public:
  Parser(std::string file_contents);

  void Next();
  int GetCommand();
  int GetMagnitude();
};

#endif