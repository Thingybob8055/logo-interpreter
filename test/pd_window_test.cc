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

TEST(PDWindowTest, should_exit_method) {
  PDWindow window;
  ungetch('q');
  bool should_exit;
  should_exit = window.ShouldExit();
  EXPECT_TRUE(should_exit);
}