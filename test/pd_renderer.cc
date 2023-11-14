#include "pd_renderer.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>

char *ReadStringFromWindow(WINDOW *win, int y, int x, int len) {
  char *str = (char *)malloc(len + 1);
  mvwinstr(win, y, x, str);
  str[len] = '\0';
  return str;
}

TEST(DisplayGraphicsTest, CreateRenderer) {
  WINDOW *win = initscr();
  int y_start_location = 1;
  int x_start_location = 1;
  int y_max_coordinate;
  int x_max_coordinate;
  getmaxyx(stdscr, y_max_coordinate, x_max_coordinate);
  char *leading_string = (char *)"c";
  PDRender *renderer =
      CreateRenderer(win, y_start_location, x_start_location, leading_string);
  ASSERT_EQ(x_start_location, renderer->x_location);
  ASSERT_EQ(y_start_location, renderer->y_location);
  ASSERT_EQ(renderer->y_safe_zone, y_max_coordinate - 2);
  ASSERT_EQ(renderer->x_safe_zone, x_max_coordinate - 2);
  ASSERT_STREQ(leading_string, renderer->leading_character);
  free(renderer);
}

// TODO: Add cases for other last command values
TEST(DisplayGraphicsTest, Render) {
  WINDOW *win = initscr();
  int y_start_location = 1;
  int x_start_location = 1;
  int return_value = 0;
  char *leading_string = (char *)"c";
  int window_x_max_coordinate = 10;
  int window_y_max_coordinate = 10;
  win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
  PDRender *renderer =
      CreateRenderer(win, y_start_location, x_start_location, leading_string);
  return_value = Render(renderer);
  ASSERT_EQ(x_start_location, renderer->x_location);
  ASSERT_EQ(y_start_location, renderer->y_location);
  ASSERT_EQ(leading_string, renderer->leading_character);
  ASSERT_EQ(return_value, OK);
  char *str = ReadStringFromWindow(win, y_start_location, x_start_location, 1);
  ASSERT_STREQ(leading_string, str);
  renderer->last_command = KEY_RIGHT;
  renderer->trailing_character = (char *)"t";
  return_value = Render(renderer);
  char *trailing_char =
      ReadStringFromWindow(win, y_start_location, x_start_location - 1, 1);
  ASSERT_EQ(return_value, OK);
  ASSERT_STREQ(renderer->trailing_character, trailing_char);
  free(str);
  free(trailing_char);
  free(renderer);
}

TEST(DisplayGraphicsTest, MoveRight) {
  WINDOW *win = initscr();
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"▶";
  int window_x_max_coordinate = 4;
  int window_y_max_coordinate = 4;
  win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
  PDRender *renderer =
      CreateRenderer(win, y_start_location, x_start_location, leading_string);
  MoveRight(renderer);
  ASSERT_STREQ(leading_string, renderer->leading_character);
  ASSERT_EQ(x_start_location + 1, renderer->x_location);
  free(renderer);
}

// TODO: Test for other cases
TEST(DisplayGraphicsTest, BoundaryCheck) {
  WINDOW *win = initscr();
  int y_start_location = 8;
  int x_start_location = 8;
  char *leading_string = (char *)"c";
  int window_x_max_coordinate = 10;
  int window_y_max_coordinate = 10;
  win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
  PDRender *renderer =
      CreateRenderer(win, y_start_location, x_start_location, leading_string);
  MoveRight(renderer);
  ASSERT_EQ(x_start_location, renderer->x_location);
  MoveRight(renderer);
  free(renderer);
}

TEST(DisplayGraphicsTest, SetTrailingCharacter) {
  WINDOW *win = initscr();
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"c";
  int window_x_max_coordinate = 10;
  int window_y_max_coordinate = 10;
  win = newwin(window_y_max_coordinate, window_y_max_coordinate, 0, 0);
  PDRender *renderer =
      CreateRenderer(win, y_start_location, x_start_location, leading_string);
  SetTrailingCharacter(renderer);
  ASSERT_STREQ(renderer->trailing_character, (char *)"─");
}

TEST(DisplayGraphicsTest, Move) {
  WINDOW *win = initscr();
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"c";
  int window_x_max_coordinate = 10;
  int window_y_max_coordinate = 10;
  win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
  PDRender *renderer =
      CreateRenderer(win, y_start_location, x_start_location, leading_string);
  Move(renderer, KEY_RIGHT);
  ASSERT_EQ(x_start_location + 1, renderer->x_location);
  free(renderer);
}