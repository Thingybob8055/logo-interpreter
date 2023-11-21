#ifndef LOGO_PARSER_H_
#define LOGO_PARSER_H_

#include <string.h>

#include <iostream>
#include <map>
#include <sstream>

#include "keys.h"

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