#ifndef LOGO_REPEAT_HANDLER_H_
#define LOGO_REPEAT_HANDLER_H_

#include <functional>
#include <iostream>
#include <sstream>
#include <string>

class LogoRepeatHandler {
 private:
  /* data */
 public:
  std::stringstream handle(std::stringstream &ss) const;
};

#endif  // LOGO_REPEAT_HANDLER_H_
