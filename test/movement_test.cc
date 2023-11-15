#include "movement/movement.h"

#include <curses.h>
#include <gtest/gtest.h>
#include <stdio.h>

TEST(MovementTest, when_constructor_called_expect_movement_to_be_created) {
  // Arrange
  int x_start_location = 1;
  int y_start_location = 1;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  // Act
  auto movement = Movement(x_start_location, y_start_location, x_safe_zone,
                           y_safe_zone, assembler);

  // Assert
  ASSERT_EQ(x_start_location, movement.GetXLocation());
  ASSERT_EQ(y_start_location, movement.GetYLocation());
  ASSERT_EQ(x_safe_zone, movement.GetXSafeZone());
  ASSERT_EQ(y_safe_zone, movement.GetYSafeZone());
  ASSERT_EQ(PEN_DOWN, movement.GetPenPosition());
}

TEST(MovementTest, when_move_up_called_expect_y_location_to_decrement_by_one) {
  // Arrange
  int x_start_location = 2;
  int y_start_location = 2;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  CharacterAssembler *assembler = new CharacterAssembler();

  // Act
  auto movement = Movement(x_start_location, y_start_location, x_safe_zone,
                           y_safe_zone, assembler);

  // Act
  movement.MoveUp();

  // Assert
  ASSERT_EQ(x_start_location, movement.GetXLocation());
  ASSERT_EQ(y_start_location - 1, movement.GetYLocation());
}

TEST(MovementTest,
     when_move_down_called_expect_y_location_to_increment_by_one) {
  // Arrange
  int x_start_location = 2;
  int y_start_location = 2;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  CharacterAssembler *assembler = new CharacterAssembler();

  // Act
  auto movement = Movement(x_start_location, y_start_location, x_safe_zone,
                           y_safe_zone, assembler);

  // Act
  movement.MoveDown();

  // Assert
  ASSERT_EQ(x_start_location, movement.GetXLocation());
  ASSERT_EQ(y_start_location + 1, movement.GetYLocation());
}

TEST(MovementTest,
     when_move_left_called_expect_x_location_to_decrement_by_one) {
  // Arrange
  int x_start_location = 2;
  int y_start_location = 2;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  CharacterAssembler *assembler = new CharacterAssembler();

  // Act
  auto movement = Movement(x_start_location, y_start_location, x_safe_zone,
                           y_safe_zone, assembler);

  // Act
  movement.MoveLeft();

  // Assert
  ASSERT_EQ(x_start_location - 1, movement.GetXLocation());
  ASSERT_EQ(y_start_location, movement.GetYLocation());
}

TEST(MovementTest,
     when_move_right_called_expect_x_location_to_increment_by_one) {
  // Arrange
  int x_start_location = 2;
  int y_start_location = 2;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  CharacterAssembler *assembler = new CharacterAssembler();

  // Act
  auto movement = Movement(x_start_location, y_start_location, x_safe_zone,
                           y_safe_zone, assembler);

  // Act
  movement.MoveRight();

  // Assert
  ASSERT_EQ(x_start_location + 1, movement.GetXLocation());
  ASSERT_EQ(y_start_location, movement.GetYLocation());
}