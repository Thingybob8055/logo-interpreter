#include "pd_renderer.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>

TEST(DisplayGraphicsTest, CreateRenderer) {
  WINDOW *win = initscr();
  int y = 1;
  int x = 1;
  char *c = (char *)"c";
  PDRender *renderer = CreateRenderer(win, y, x, c);
  ASSERT_EQ(x, renderer->x_location);
  ASSERT_EQ(y, renderer->y_location);
  ASSERT_STREQ(c, renderer->leading_character);
}