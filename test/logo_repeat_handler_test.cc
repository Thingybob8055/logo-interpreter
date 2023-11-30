#include "parser/logo_repeat_handler.h"

#include <gtest/gtest.h>

TEST(LogoRepeatHandlerTest, when_given_a_repeat_command_then_return_the_command_repeated) {
    std::stringstream ss;
    ss << "repeat 4 [ fd 50 rt 90 ]";
    auto handler = LogoRepeatHandler();
    auto out = handler.handle(ss);
    std::string expected = "fd 50 rt 90 \nfd 50 rt 90 \nfd 50 rt 90 \nfd 50 rt 90 \n";
    EXPECT_EQ(out.str(), expected);
}

TEST(LogoRepeatHandlerTest, when_given_no_repeat_command_then_return_the_command) {
    std::stringstream ss;
    ss << "fd 50 rt 90";
    auto handler = LogoRepeatHandler();
    auto out = handler.handle(ss);
    std::string expected = "fd 50 rt 90\n";
    EXPECT_EQ(out.str(), expected);
}
