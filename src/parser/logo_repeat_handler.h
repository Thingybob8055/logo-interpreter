#ifndef LOGO_REPEAT_HANDLER_H_
#define LOGO_REPEAT_HANDLER_H_

#include <functional>
#include <iostream>
#include <sstream>
#include <string>

class LogoRepeatHandler {
 public:
  std::stringstream Handle(std::stringstream &ss) const;
};

#endif  // LOGO_REPEAT_HANDLER_H_
