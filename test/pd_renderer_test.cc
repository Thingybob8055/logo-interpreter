#include "renderer/pd_renderer.h"

#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>

#include "box/pd_box.h"
#include "keys.h"
#include "movement/pd_movement.h"

char *ReadStringFromWindow(WINDOW *win, int y, int x) {
  static char str[3];
  mvwinstr(win, y, x, str);
  str[3] = '\0';
  return str;
}

TEST(PDRendererTest, when_constructed_expect_renderer_to_be_created) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 1;
  int x_start_location = 1;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);

  // Act
  PDRenderer renderer = PDRenderer(box, movement);

  // Assert

  ASSERT_EQ(box, renderer.GetBox());
  ASSERT_EQ(movement, renderer.GetMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_when_going_forwards_with_heading_set_to_right_and_magntitude_1_expect_x_location_to_increment_by_two) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 2;
  int x_start_location = 2;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  movement->TurnRight90();

  // Act
  renderer.Move(KEY_UP, 1);

  // Assert
  ASSERT_EQ(x_start_location + 2, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_when_going_forwards_with_heading_set_to_up_and_magntitude_1_expect_y_location_to_decrement_by_one) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 2;
  int x_start_location = 2;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  // Act
  renderer.Move(KEY_UP, 1);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location - 1, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_when_going_forwards_with_heading_down_and_magntitude_1_expect_y_location_to_increment_by_one) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 2;
  int x_start_location = 2;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  movement->TurnRight90();
  movement->TurnRight90();

  // Act
  renderer.Move(KEY_UP, 1);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location + 1, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_when_going_forwards_with_heading_left_and_magntitude_1_expect_x_location_to_decrement_by_two) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 5;
  int x_start_location = 5;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  movement->TurnRight90();
  movement->TurnRight90();
  movement->TurnRight90();

  // Act
  renderer.Move(KEY_UP, 1);

  // Assert
  ASSERT_EQ(x_start_location - 2, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_when_going_backwards_expect_x_location_to_decrement_by_two) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 5;
  int x_start_location = 5;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, 10, 10, assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  movement->TurnRight90();

  // Act
  renderer.Move(KEY_DOWN, 1);

  // Assert
  ASSERT_EQ(x_start_location - 2, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_when_going_backwards_expect_y_location_to_increment_by_one) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 5;
  int x_start_location = 5;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, 10, 10, assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  // Act
  renderer.Move(KEY_DOWN, 1);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location + 1, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_when_going_backwards_expect_y_location_to_decrement_by_one) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 5;
  int x_start_location = 5;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, 10, 10, assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  renderer.Move(KEY_LEFT, 1);
  renderer.Move(KEY_LEFT, 1);

  // Act
  renderer.Move(KEY_DOWN, 1);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location - 1, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_when_going_backwards_expect_x_location_to_increment_by_two) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 5;
  int x_start_location = 5;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, 10, 10, assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  renderer.Move(KEY_RIGHT, 1);
  renderer.Move(KEY_RIGHT, 1);
  renderer.Move(KEY_RIGHT, 1);

  // Act
  renderer.Move(KEY_DOWN, 1);

  // Assert
  ASSERT_EQ(x_start_location + 2, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(PDRendererTest,
     when_move_called_with_key_space_expect_pen_position_to_be_toggled) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 2;
  int x_start_location = 2;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  // Act
  renderer.Move(KEY_SPACE, 1);

  // Assert
  ASSERT_EQ(PEN_UP, renderer.GetPenPositionFromMovement());

  // Act
  renderer.Move(KEY_SPACE, 1);

  // Assert
  ASSERT_EQ(PEN_DOWN, renderer.GetPenPositionFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    Render_when_when_going_forwards_called_expect_leading_character_to_be_written_to_window) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 1;
  int x_start_location = 1;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  // Act
  int return_value = renderer.Render();

  // Assert
  char *read_string = ReadStringFromWindow(win->GetWindow(), y_start_location,
                                           x_start_location);
  ASSERT_STREQ(read_string, assembler->GetLeadingCharacter());
  ASSERT_EQ(OK, return_value);

  // cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    Render_when_called_when_going_forwards_expect_trailing_character_to_be_written_to_window_when_heading_is_right_and_mangitude_is_1) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 1;
  int x_start_location = 1;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  // Act
  movement->TurnRight90();
  renderer.Move(KEY_UP, 1);
  int return_value = renderer.Render();

  // Assert
  char *read_string = ReadStringFromWindow(win->GetWindow(), y_start_location,
                                           x_start_location + 1);
  ASSERT_STREQ(read_string, assembler->GetTrailingCharacter());
  ASSERT_EQ(OK, return_value);

  // cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    Render_when_called_when_going_forwards_expect_trailing_character_to_be_written_to_window_when_heading_is_left_and_mangitude_is_1) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 5;
  int x_start_location = 5;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  // Act
  movement->TurnRight90();
  movement->TurnRight90();
  movement->TurnRight90();
  renderer.Move(KEY_UP, 1);
  int return_value = renderer.Render();

  // Assert
  char *read_string = ReadStringFromWindow(win->GetWindow(), y_start_location,
                                           x_start_location - 1);
  ASSERT_STREQ(read_string, assembler->GetTrailingCharacter());
  ASSERT_EQ(OK, return_value);

  // cleanup
  delete win;
  delete movement;
  delete box;
}

TEST(
    PDRendererTest,
    when_move_called_and_invalid_key_pressed_expect_x_y_location_to_remain_the_same) {
  // Arrange

  PDWindow *win = new PDWindow();
  PDBox *box = new PDBox(win);

  int y_start_location = 2;
  int x_start_location = 2;
  CharacterAssembler *assembler = new CharacterAssembler();
  PDMovement *movement =
      new PDMovement(y_start_location, x_start_location, box->GetYSafeZone(),
                     box->GetXSafeZone(), assembler);
  PDRenderer renderer = PDRenderer(box, movement);

  // Act
  renderer.Move(0, 0);

  // Assert
  ASSERT_EQ(x_start_location, renderer.GetXLocationFromMovement());
  ASSERT_EQ(y_start_location, renderer.GetYLocationFromMovement());

  // Cleanup
  delete win;
  delete movement;
  delete box;
}