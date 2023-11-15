#include "renderer/pd_renderer.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>

#include "movement/movement.h"

char *ReadStringFromWindow(WINDOW *win, int y, int x) {
  static char str[3];
  mvwinstr(win, y, x, str);
  str[3] = '\0';
  return str;
}

TEST(PDRendererTest, when_constructed_expect_renderer_to_be_created) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;

  // Act
  auto renderer = PDRenderer(win, y_start_location, x_start_location);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location, renderer.GetYLocationFromMovement());
  ASSERT_EQ(win->GetYMaxScreenCoordinate() - 3, renderer.GetYSafeZone());
  ASSERT_EQ(win->GetXMaxScreenCoordinate() - 4, renderer.GetXSafeZone());
  // Cleanup
  delete win;
}

TEST(PDRendererTest,
     when_move_called_with_key_right_expect_x_location_to_increment_by_one) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 2;
  int x_start_location = 2;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_RIGHT);

  // Assert
  ASSERT_EQ(x_start_location + 1, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
}

TEST(PDRendererTest,
     when_move_called_with_key_left_expect_x_location_to_decrement_by_one) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 2;
  int x_start_location = 2;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_LEFT);

  // Assert
  ASSERT_EQ(x_start_location - 1, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
}

TEST(PDRendererTest,
     when_move_called_with_key_up_expect_y_location_to_decrement_by_one) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 2;
  int x_start_location = 2;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_UP);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location - 1, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
}

TEST(PDRendererTest,
     when_move_called_with_key_down_expect_y_location_to_increment_by_one) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 2;
  int x_start_location = 2;
  char *leading_string = (char *)"c";
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_DOWN);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location + 1, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
}

TEST(PDRendererTest,
     when_move_called_with_key_space_expect_pen_position_to_be_toggled) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 2;
  int x_start_location = 2;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_SPACE);

  // Assert
  ASSERT_EQ(PEN_UP, renderer.GetPenPositionFromMovement());

  // Act
  renderer.Move(KEY_SPACE);

  // Assert
  ASSERT_EQ(PEN_DOWN, renderer.GetPenPositionFromMovement());

  // Cleanup
  delete win;
}

TEST(PDRendererTest,
     Render_when_called_expect_leading_character_to_be_written_to_window) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  int return_value = renderer.Render();

  // Assert
  char *read_string = ReadStringFromWindow(win->GetWindow(), y_start_location,
                                           x_start_location);
  ASSERT_STREQ(read_string, renderer.GetLeadingCharacterFromMovement());
  ASSERT_EQ(OK, return_value);

  // free(read_string);
  delete win;
}

TEST(
    PDRendererTest,
    Render_when_called_expect_trailing_character_to_be_written_to_window_when_last_command_is_right) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 1;
  int x_start_location = 1;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_RIGHT);
  int return_value = renderer.Render();

  // Assert
  char *read_string = ReadStringFromWindow(win->GetWindow(), y_start_location,
                                           x_start_location);
  ASSERT_STREQ(read_string, renderer.GetTrailingCharacterFromMovement());
  ASSERT_EQ(OK, return_value);

  // free(read_string);
  delete win;
}

TEST(
    PDRendererTest,
    Render_when_called_expect_trailing_character_to_be_written_to_window_when_last_command_is_left) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 5;
  int x_start_location = 5;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_LEFT);
  int return_value = renderer.Render();

  // Assert
  char *read_string = ReadStringFromWindow(win->GetWindow(), y_start_location,
                                           x_start_location);
  ASSERT_STREQ(read_string, renderer.GetTrailingCharacterFromMovement());
  ASSERT_EQ(OK, return_value);

  // free(read_string);
  delete win;
}

TEST(
    PDRendererTest,
    Render_when_called_expect_trailing_character_to_be_written_to_window_when_last_command_is_up) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 5;
  int x_start_location = 5;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_UP);
  int return_value = renderer.Render();

  // Assert
  char *read_string = ReadStringFromWindow(win->GetWindow(), y_start_location,
                                           x_start_location);
  ASSERT_STREQ(read_string, renderer.GetTrailingCharacterFromMovement());
  ASSERT_EQ(OK, return_value);

  // free(read_string);
  delete win;
}

TEST(
    PDRendererTest,
    Render_when_called_expect_trailing_character_to_be_written_to_window_when_last_command_is_down) {
  // Arrange
  char *ptest[0];
  PDWindow *win = new PDWindow(0, ptest);
  int y_start_location = 5;
  int x_start_location = 5;
  PDRenderer renderer = PDRenderer(win, y_start_location, x_start_location);

  // Act
  renderer.Move(KEY_DOWN);
  int return_value = renderer.Render();

  // Assert
  char *read_string = ReadStringFromWindow(win->GetWindow(), y_start_location,
                                           x_start_location);
  ASSERT_STREQ(read_string, renderer.GetTrailingCharacterFromMovement());
  ASSERT_EQ(OK, return_value);

  // free(read_string);
  delete win;
}