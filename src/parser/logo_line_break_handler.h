#ifndef LOGO_LINE_BREAK_HANDLER_H_
#define LOGO_LINE_BREAK_HANDLER_H_

#include <sstream>
#include <string>

class LogoLineBreakHandler {
 public:
  std::stringstream handle(std::stringstream &ss) const;
};

#endif  // LOGO_LINE_BREAK_HANDLER_H_
