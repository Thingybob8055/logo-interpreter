#include "parser/logo_line_break_handler.h"

#include <gtest/gtest.h>

TEST(
    LogoLineBreakHandlerTest,
    when_given_a_two_commands_with_magnitude_on_same_line_then_return_the_command_with_a_line_break) {
  std::stringstream ss;
  ss << "fd 50 rt 90";
  auto handler = LogoLineBreakHandler();
  auto out = handler.Handle(ss);
  std::string expected = "fd 50\nrt 90\n";
  EXPECT_EQ(out.str(), expected);
}

TEST(
    LogoLineBreakHandlerTest,
    when_given_a_two_commands_without_magnitude_on_same_line_then_return_the_command_with_a_line_break) {
  std::stringstream ss;
  ss << "pu pd";
  auto handler = LogoLineBreakHandler();
  auto out = handler.Handle(ss);
  std::string expected = "pu\npd\n";
  EXPECT_EQ(out.str(), expected);
}

TEST(
    LogoLineBreakHandlerTest,
    when_given_repeat_should_not_break_line) {
  std::stringstream ss;
  ss << "pu repeat 4 [ fd 50 rt 90 ] pd";
  auto handler = LogoLineBreakHandler();
  auto out = handler.Handle(ss);
  std::string expected = "pu\nrepeat 4 [ fd 50 rt 90 ]\npd\n";
  EXPECT_EQ(out.str(), expected);
}

TEST(
    LogoLineBreakHandlerTest,
    when_given_a_two_commands_on_separate_lines_then_return_the_command_with_a_line_break) {
  std::stringstream ss;
  ss << "fd 50\nrt 90";
  auto handler = LogoLineBreakHandler();
  auto out = handler.Handle(ss);
  std::string expected = "fd 50\nrt 90\n";
  EXPECT_EQ(out.str(), expected);
}
