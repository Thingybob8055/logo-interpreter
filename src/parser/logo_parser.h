#ifndef LOGO_PARSER_H_
#define LOGO_PARSER_H_

#define KEY_SPACE 32

#include <iostream>
#include <sstream>
#include <string.h>
#include <curses.h>
#include <map>

class Parser {
private:
    std::stringstream data;
    std::string buf;
    int command;
    int magnitude;
public:
    std::map<std::string, int> commandMap;
    Parser(std::string fileContents);
    void next();
    int getCommand();
    int getMagnitude();
};


#endif