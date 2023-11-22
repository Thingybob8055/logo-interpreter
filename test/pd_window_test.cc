#include "window/pd_window.h"

#include <gtest/gtest.h>

TEST(PDWindowTest, when_constructed_expect_window_to_be_created) {
  // Arrange & Act
  auto window = std::make_unique<PDWindow>();
  // Assert
  EXPECT_NE(window->GetWindow(), nullptr);
  EXPECT_EQ(window->GetYMaxScreenCoordinate(), 24);
  EXPECT_EQ(window->GetXMaxScreenCoordinate(), 80);
}

TEST(PDWindowTest, when_get_input_expect_input_to_be_returned) {
  // Arrange
  ungetch('a');
  char read_char;
  // Act
  auto window = std::make_unique<PDWindow>();
  read_char = window->GetInput();
  // Assert
  EXPECT_EQ(read_char, 'a');
}
