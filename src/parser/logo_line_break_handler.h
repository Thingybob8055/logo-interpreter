#ifndef LOGO_LINE_BREAK_HANDLER_H_
#define LOGO_LINE_BREAK_HANDLER_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class LogoLineBreakHandler {
 public:
  std::stringstream Handle(std::stringstream &ss) const;
};

#endif  // LOGO_LINE_BREAK_HANDLER_H_
