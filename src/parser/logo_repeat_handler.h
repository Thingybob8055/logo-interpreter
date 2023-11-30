#ifndef LOGO_REPEAT_HANDLER_H_
#define LOGO_REPEAT_HANDLER_H_

#include <string>
#include <sstream>
#include <iostream>
#include <functional>

class LogoRepeatHandler {
 private:
  /* data */
 public:
  std::stringstream handle(std::stringstream &ss) const;
};

#endif  // LOGO_REPEAT_HANDLER_H_
