#include "renderer/pd_renderer.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>

char *ReadStringFromWindow(WINDOW *win, int y, int x, int len) {
  char *str = (char *)malloc(len + 1);
  mvwinstr(win, y, x, str);
  str[len] = '\0';
  return str;
}

TEST(PDRendererTest, when_constructed_expect_renderer_to_be_created) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"c";

  // Act
  auto renderer =
      PDRenderer(win, y_start_location, x_start_location, leading_string, KEY_RIGHT, PEN_DOWN);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocation());
  ASSERT_EQ(y_start_location, renderer.GetYLocation());
  ASSERT_EQ(win->GetYMaxScreenCoordinate() - 3, renderer.GetYSafeZone());
  ASSERT_EQ(win->GetXMaxScreenCoordinate() - 4, renderer.GetXSafeZone());
  ASSERT_STREQ(leading_string, renderer.GetLeadingCharacter());
  ASSERT_EQ(PEN_DOWN, renderer.GetPenPosition());

  // Cleanup
  delete win;
}

// TEST(DisplayGraphicsTest,
//      Render_when_called_expect_leading_character_to_be_written_to_window) {
//   // Arrange
//   char *ptest[0];
//   PDWindow *win = new PDWindow(0, ptest);
//   int y_start_location = 1;
//   int x_start_location = 1;
//   char *leading_string = (char *)"c";
//   PDRenderer renderer =
//       PDRenderer(win, y_start_location, x_start_location, leading_string);

//   // Act
//   int return_value = renderer.Render();

//   // Assert
//   char *str = ReadStringFromWindow(win->GetWindow(), y_start_location,
//                                    x_start_location, 1);
//   ASSERT_STREQ(str, renderer.GetLeadingCharacter());
//   ASSERT_EQ(OK, return_value);

//   free(str);
//   delete win;
// }

// TEST(
//     DisplayGraphicsTest,
//     Render_when_called_expect_trailing_character_to_be_written_to_window_when_last_command_is_right)
//     {
//   // Arrange
//   PDWindow *win = new PDWindow(0, NULL);
//   int y_start_location = 1;
//   int x_start_location = 1;
//   int return_value = 0;
//   char *leading_string = (char *)"c";
//   PDRenderer renderer =
//       PDRenderer(win, y_start_location, x_start_location, leading_string);

//   // Act
//   // renderer->last_command = KEY_RIGHT;
//   // renderer->trailing_character = (char *)"t";
//   return_value = renderer.Render();
//   char *trailing_char =
//       ReadStringFromWindow(win->GetWindow(), y_start_location,
//       x_start_location - 1, 1);

//   // Assert
//   ASSERT_STREQ(trailing_char, renderer.GetTrailingCharacter());

//   // Cleanup
//   free(trailing_char);
//   delete win;
// }

// TEST(
//     DisplayGraphicsTest,
//     Render_when_called_expect_trailing_character_to_be_written_to_window_when_last_command_is_left)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 2;
//   int return_value = 0;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   renderer->last_command = KEY_LEFT;
//   renderer->trailing_character = (char *)"t";
//   return_value = Render(renderer);
//   char *trailing_char =
//       ReadStringFromWindow(win, y_start_location, x_start_location + 1, 1);

//   // Assert
//   ASSERT_STREQ(trailing_char, renderer->trailing_character);

//   // Cleanup
//   free(trailing_char);
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     Render_when_called_expect_trailing_character_to_be_written_to_window_when_last_command_is_up)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 2;
//   int x_start_location = 1;
//   int return_value = 0;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   renderer->last_command = KEY_UP;
//   renderer->trailing_character = (char *)"t";
//   return_value = Render(renderer);
//   char *trailing_char =
//       ReadStringFromWindow(win, y_start_location + 1, x_start_location, 1);

//   // Assert
//   ASSERT_STREQ(trailing_char, renderer->trailing_character);

//   // Cleanup
//   free(trailing_char);
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     Render_when_called_expect_trailing_character_to_be_written_to_window_when_last_command_is_down)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 1;
//   int return_value = 0;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   renderer->last_command = KEY_DOWN;
//   renderer->trailing_character = (char *)"t";
//   return_value = Render(renderer);
//   char *trailing_char =
//       ReadStringFromWindow(win, y_start_location - 1, x_start_location, 1);

//   // Assert
//   ASSERT_STREQ(trailing_char, renderer->trailing_character);

//   // Cleanup
//   free(trailing_char);
//   free(renderer);
// }

TEST(DisplayGraphicsTest,
     Move_when_key_right_expect_x_location_to_increment_by_one) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"▶";
  PDRenderer renderer =
      PDRenderer(win, y_start_location, x_start_location, leading_string, KEY_RIGHT, PEN_DOWN);

  // Act
  renderer.Move(KEY_RIGHT);

  // Assert
  ASSERT_STREQ(leading_string, renderer.GetLeadingCharacter());
  ASSERT_EQ(x_start_location + 1, renderer.GetXLocation());

  // Cleanup
  delete win;
}

TEST(DisplayGraphicsTest,
     Move_when_key_left_expect_x_location_to_decrement_by_one) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 2;
  char *leading_string = (char *)"◀";
  PDRenderer renderer =
      PDRenderer(win, y_start_location, x_start_location, leading_string, KEY_RIGHT, PEN_DOWN);

  // Act
  renderer.Move(KEY_LEFT);

  // Assert
  ASSERT_STREQ(leading_string, renderer.GetLeadingCharacter());
  ASSERT_EQ(x_start_location - 1, renderer.GetXLocation());

  // Cleanup
  delete win;
}

TEST(DisplayGraphicsTest,
     Move_when_key_up_expect_y_location_to_decrement_by_one) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 2;
  int x_start_location = 1;
  char *leading_string = (char *)"▲";
  PDRenderer renderer =
      PDRenderer(win, y_start_location, x_start_location, leading_string, KEY_RIGHT, PEN_DOWN);

  // Act
  renderer.Move(KEY_UP);

  // Assert
  ASSERT_STREQ(leading_string, renderer.GetLeadingCharacter());
  ASSERT_EQ(y_start_location - 1, renderer.GetYLocation());

  // Cleanup
  delete win;
}

TEST(DisplayGraphicsTest,
     Move_when_key_down_expect_y_location_to_increment_by_one) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"▼";
  PDRenderer renderer =
      PDRenderer(win, y_start_location, x_start_location, leading_string, KEY_RIGHT, PEN_DOWN);

  // Act
  renderer.Move(KEY_DOWN);

  // Assert
  ASSERT_STREQ(leading_string, renderer.GetLeadingCharacter());
  ASSERT_EQ(y_start_location + 1, renderer.GetYLocation());

  // Cleanup
  delete win;
}

// TEST(
//     DisplayGraphicsTest,
//     BoundaryCheck_when_x_location_is_greater_than_x_safe_zone_expect_x_location_to_be_set_to_x_safe_zone)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 8;
//   int x_start_location = 8;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   MoveRight(renderer);

//   // Assert
//   ASSERT_EQ(x_start_location, renderer->x_location);

//   // Cleanup
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     BoundaryCheck_when_x_location_is_less_than_ceiling_cap_expect_x_location_to_be_set_to_ceiling_cap)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 8;
//   int x_start_location = 1;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   int ceiling_cap = 1;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   MoveLeft(renderer);

//   // Assert
//   ASSERT_EQ(ceiling_cap, renderer->x_location);

//   // Cleanup
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     BoundaryCheck_when_y_location_is_greater_than_y_safe_zone_expect_y_location_to_be_set_to_y_safe_zone)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 8;
//   int x_start_location = 8;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   MoveDown(renderer);

//   // Assert
//   ASSERT_EQ(y_start_location, renderer->y_location);

//   // Cleanup
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     BoundaryCheck_when_y_location_is_less_than_ceiling_cap_expect_y_location_to_be_set_to_ceiling_cap)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 8;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   int ceiling_cap = 1;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   MoveUp(renderer);

//   // Assert
//   ASSERT_EQ(ceiling_cap, renderer->y_location);

//   // Cleanup
//   free(renderer);
// }

// // TEST(DisplayGraphicsTest,
// //
// SetTrailingCharacter_when_called_and_pen_up_expect_trailing_character_not_to_be_set)
// // {
// //   // Arrange
// //   WINDOW *win = initscr();
// //   int y_start_location = 1;
// //   int x_start_location = 1;
// //   char *leading_string = (char *)"c";
// //   int window_x_max_coordinate = 10;
// //   int window_y_max_coordinate = 10;
// //   win = newwin(window_y_max_coordinate, window_y_max_coordinate, 0, 0);
// //   PDRender *renderer =
// //       CreateRenderer(win, y_start_location, x_start_location,
// //       leading_string);

// //   renderer->pen_position = PEN_UP;

// //   // Act
// //   SetTrailingCharacter(renderer);

// //   // Assert
// //   ASSERT_STREQ((char *)" ", renderer->trailing_character);
// // }

// TEST(DisplayGraphicsTest,
//      Move_when_called_expect_x_location_to_change_to_right) {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 1;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   Move(renderer, KEY_RIGHT);

//   // Assert
//   ASSERT_EQ(x_start_location + 1, renderer->x_location);

//   // Cleanup
//   free(renderer);
// }

// TEST(DisplayGraphicsTest,
//      Move_when_called_expect_x_location_to_change_to_left) {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 2;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   int ceiling_cap = 1;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, ceiling_cap, x_start_location, leading_string);

//   // Act
//   Move(renderer, KEY_LEFT);

//   // Assert
//   ASSERT_EQ(x_start_location - 1, renderer->x_location);

//   // Cleanup
//   free(renderer);
// }

// TEST(DisplayGraphicsTest, Move_when_called_expect_y_location_to_change_to_up)
// {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 2;
//   int x_start_location = 1;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   int ceiling_cap = 1;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, ceiling_cap, leading_string);

//   // Act
//   Move(renderer, KEY_UP);

//   // Assert
//   ASSERT_EQ(y_start_location - 1, renderer->y_location);

//   // Cleanup
//   free(renderer);
// }

// TEST(DisplayGraphicsTest,
//      Move_when_called_expect_y_location_to_change_to_down) {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 1;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   int ceiling_cap = 1;
//   win = newwin(window_y_max_coordinate, window_x_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, ceiling_cap, x_start_location, leading_string);

//   // Act
//   Move(renderer, KEY_DOWN);

//   // Assert
//   ASSERT_EQ(y_start_location + 1, renderer->y_location);

//   // Cleanup
//   free(renderer);
// }

TEST(DisplayGraphicsTest,
     Move_when_called_with_space_and_pen_down_expect_pen_postion_set_pen_up) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"c";
  PDRenderer renderer =
      PDRenderer(win, y_start_location, x_start_location, leading_string, KEY_RIGHT, PEN_DOWN);

  // Act
  renderer.Move(KEY_SPACE);

  // Assert
  ASSERT_EQ(PEN_UP, renderer.GetPenPosition());

  // Cleanup
  delete win;
}

TEST(DisplayGraphicsTest,
     Move_when_called_with_space_and_pen_up_expect_pen_postion_set_pen_down) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"c";
  PDRenderer renderer =
      PDRenderer(win, y_start_location, x_start_location, leading_string, KEY_RIGHT, PEN_UP);

  // Act
  renderer.Move(KEY_SPACE);

  // Assert
  ASSERT_EQ(PEN_DOWN, renderer.GetPenPosition());

  // Cleanup
  delete win;
}

TEST(DisplayGraphicsTest,
     Move_when_called_with_unknown_command_coordinates_remain_the_same) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;
  char *leading_string = (char *)"c";
  PDRenderer renderer =
      PDRenderer(win, y_start_location, x_start_location, leading_string, KEY_RIGHT, PEN_DOWN);

  // Act
  renderer.Move(0);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocation());
  ASSERT_EQ(y_start_location, renderer.GetYLocation());
  ASSERT_EQ(PEN_DOWN, renderer.GetPenPosition());

  // Cleanup
  delete win;
}

// TEST(
//     DisplayGraphicsTest,
//     TrailingCharacter_when_called_returns_correspondong_trailing_character_when_current_command_is_key_down)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 1;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   win = newwin(window_y_max_coordinate, window_y_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   const char *returned_string_1;
//   const char *returned_string_2;
//   const char *returned_string_3;
//   renderer->last_command = KEY_LEFT;
//   returned_string_1 = TrailingCharacter(renderer, KEY_DOWN);
//   renderer->last_command = KEY_RIGHT;
//   returned_string_2 = TrailingCharacter(renderer, KEY_DOWN);
//   renderer->last_command = KEY_UP;
//   returned_string_3 = TrailingCharacter(renderer, KEY_DOWN);

//   // Assert
//   ASSERT_STREQ((char *)"┌", returned_string_1);
//   ASSERT_STREQ((char *)"┐", returned_string_2);
//   ASSERT_STREQ((char *)"│", returned_string_3);

//   // Cleanup
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     TrailingCharacter_when_called_returns_correspondong_trailing_character_when_current_command_is_key_up)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 2;
//   int x_start_location = 1;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;

//   win = newwin(window_y_max_coordinate, window_y_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   const char *returned_string_1;
//   const char *returned_string_2;
//   const char *returned_string_3;
//   renderer->last_command = KEY_LEFT;
//   returned_string_1 = TrailingCharacter(renderer, KEY_UP);
//   renderer->last_command = KEY_RIGHT;
//   returned_string_2 = TrailingCharacter(renderer, KEY_UP);
//   renderer->last_command = KEY_DOWN;
//   returned_string_3 = TrailingCharacter(renderer, KEY_UP);

//   // Assert
//   ASSERT_STREQ((char *)"└", returned_string_1);
//   ASSERT_STREQ((char *)"┘", returned_string_2);
//   ASSERT_STREQ((char *)"│", returned_string_3);

//   // Cleanup
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     TrailingCharacter_when_called_returns_correspondong_trailing_character_when_current_command_is_key_right)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 2;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;

//   win = newwin(window_y_max_coordinate, window_y_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   const char *returned_string_1;
//   const char *returned_string_2;
//   const char *returned_string_3;
//   renderer->last_command = KEY_UP;
//   returned_string_1 = TrailingCharacter(renderer, KEY_RIGHT);
//   renderer->last_command = KEY_DOWN;
//   returned_string_2 = TrailingCharacter(renderer, KEY_RIGHT);
//   renderer->last_command = KEY_LEFT;
//   returned_string_3 = TrailingCharacter(renderer, KEY_RIGHT);

//   // Assert
//   ASSERT_STREQ((char *)"┌", returned_string_1);
//   ASSERT_STREQ((char *)"└", returned_string_2);
//   ASSERT_STREQ((char *)"─", returned_string_3);

//   // Cleanup
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     TrailingCharacter_when_called_returns_correspondong_trailing_character_when_current_command_is_key_left)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 2;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;

//   win = newwin(window_y_max_coordinate, window_y_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   const char *returned_string_1;
//   const char *returned_string_2;
//   const char *returned_string_3;
//   renderer->last_command = KEY_UP;
//   returned_string_1 = TrailingCharacter(renderer, KEY_LEFT);
//   renderer->last_command = KEY_DOWN;
//   returned_string_2 = TrailingCharacter(renderer, KEY_LEFT);
//   renderer->last_command = KEY_RIGHT;
//   returned_string_3 = TrailingCharacter(renderer, KEY_LEFT);

//   // Assert
//   ASSERT_STREQ((char *)"┐", returned_string_1);
//   ASSERT_STREQ((char *)"┘", returned_string_2);
//   ASSERT_STREQ((char *)"─", returned_string_3);

//   // Cleanup
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     TrailingCharacter_when_called_returns_space_character_when_current_command_is_unknown)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 2;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;

//   win = newwin(window_y_max_coordinate, window_y_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   // Act
//   const char *returned_string;
//   renderer->last_command = KEY_UP;
//   returned_string = TrailingCharacter(renderer, 0);

//   // Assert
//   ASSERT_STREQ((char *)" ", returned_string);

//   // Cleanup
//   free(renderer);
// }

// TEST(
//     DisplayGraphicsTest,
//     SetTrailingCharacter_when_called_and_pen_up_expect_trailing_character_not_to_be_set)
//     {
//   // Arrange
//   WINDOW *win = initscr();
//   int y_start_location = 1;
//   int x_start_location = 1;
//   char *leading_string = (char *)"c";
//   int window_x_max_coordinate = 10;
//   int window_y_max_coordinate = 10;
//   win = newwin(window_y_max_coordinate, window_y_max_coordinate, 0, 0);
//   PDRender *renderer =
//       CreateRenderer(win, y_start_location, x_start_location,
//       leading_string);

//   renderer->pen_position = PEN_UP;

//   // Act
//   SetTrailingCharacter(renderer, KEY_DOWN);

//   // Assert
//   ASSERT_STREQ((char *)" ", renderer->trailing_character);
// }
