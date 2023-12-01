#include <curses.h>
#include <gtest/gtest.h>
#include <stdio.h>

#include "movement/pd_movement.h"

TEST(MovementTest, when_constructor_called_expect_movement_to_be_created) {
  // Arrange
  int x_start_location = 1;
  int y_start_location = 1;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  // Act
  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  // Assert
  ASSERT_EQ(x_start_location, movement.GetXLocation());
  ASSERT_EQ(y_start_location, movement.GetYLocation());
  ASSERT_EQ(x_safe_zone, movement.GetXSafeZone());
  ASSERT_EQ(y_safe_zone, movement.GetYSafeZone());
  ASSERT_EQ(PEN_DOWN, movement.GetPenPosition());
}

TEST(
    MovementTest,
    MovementTest_when_move_forward_called_with_heading_up_expect_y_location_to_decrement) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  // Act
  movement.MoveForward();

  // Assert
  ASSERT_EQ(x_start_location, movement.GetXLocation());
  ASSERT_EQ(y_start_location - 1, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_forward_called_with_heading_down_expect_y_location_to_increment) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnRight90();
  movement.TurnRight90();

  // Act
  movement.MoveForward();

  // Assert
  ASSERT_EQ(x_start_location, movement.GetXLocation());
  ASSERT_EQ(y_start_location + 1, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_forward_called_with_heading_left_expect_x_location_to_decrement) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnLeft90();

  // Act
  movement.MoveForward();

  // Assert
  ASSERT_EQ(x_start_location - 1, movement.GetXLocation());
  ASSERT_EQ(y_start_location, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_forward_called_with_heading_right_expect_x_location_to_increment) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnRight90();

  // Act
  movement.MoveForward();

  // Assert
  ASSERT_EQ(x_start_location + 1, movement.GetXLocation());
  ASSERT_EQ(y_start_location, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_backward_called_with_heading_up_expect_y_location_to_increment) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  // Act
  movement.MoveBackward();

  // Assert
  ASSERT_EQ(x_start_location, movement.GetXLocation());
  ASSERT_EQ(y_start_location + 1, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_backward_called_with_heading_down_expect_y_location_to_decrement) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnRight90();
  movement.TurnRight90();

  // Act
  movement.MoveBackward();

  // Assert
  ASSERT_EQ(x_start_location, movement.GetXLocation());
  ASSERT_EQ(y_start_location - 1, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_backward_called_with_heading_left_expect_x_location_to_increment) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnLeft90();

  // Act
  movement.MoveBackward();

  // Assert
  ASSERT_EQ(x_start_location + 1, movement.GetXLocation());
  ASSERT_EQ(y_start_location, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_backward_called_with_heading_right_expect_x_location_to_decrement) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnRight90();

  // Act
  movement.MoveBackward();

  // Assert
  ASSERT_EQ(x_start_location - 1, movement.GetXLocation());
  ASSERT_EQ(y_start_location, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_turn_right_90_called_with_heading_up_expect_heading_to_be_right) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  Heading expected_heading = HEADING_RIGHT;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  // Act
  movement.TurnRight90();

  // Assert
  ASSERT_EQ(expected_heading, movement.GetCurrentHeadingFromAssembler());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_turn_right_90_called_with_heading_down_expect_heading_to_be_left) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  Heading expected_heading = HEADING_LEFT;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnRight90();
  movement.TurnRight90();

  // Act
  movement.TurnRight90();

  // Assert
  ASSERT_EQ(expected_heading, movement.GetCurrentHeadingFromAssembler());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_turn_right_90_called_with_heading_left_expect_heading_to_be_up) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  Heading expected_heading = HEADING_UP;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnLeft90();

  // Act
  movement.TurnRight90();

  // Assert
  ASSERT_EQ(expected_heading, movement.GetCurrentHeadingFromAssembler());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_turn_right_90_called_with_heading_right_expect_heading_to_be_down) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  Heading expected_heading = HEADING_DOWN;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnRight90();

  // Act
  movement.TurnRight90();

  // Assert
  ASSERT_EQ(expected_heading, movement.GetCurrentHeadingFromAssembler());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_turn_left_90_called_with_heading_up_expect_heading_to_be_left) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  Heading expected_heading = HEADING_LEFT;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  // Act
  movement.TurnLeft90();

  // Assert
  ASSERT_EQ(expected_heading, movement.GetCurrentHeadingFromAssembler());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_turn_left_90_called_with_heading_down_expect_heading_to_be_right) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  Heading expected_heading = HEADING_RIGHT;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);

  movement.TurnRight90();
  movement.TurnRight90();

  // Act
  movement.TurnLeft90();

  // Assert
  ASSERT_EQ(expected_heading, movement.GetCurrentHeadingFromAssembler());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_turn_left_90_called_with_heading_left_expect_heading_to_be_down) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  Heading expected_heading = HEADING_DOWN;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);
  movement.TurnLeft90();

  // Act
  movement.TurnLeft90();

  // Assert
  ASSERT_EQ(expected_heading, movement.GetCurrentHeadingFromAssembler());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_turn_left_90_called_with_heading_right_expect_heading_to_be_up) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  Heading expected_heading = HEADING_UP;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(x_start_location, y_start_location, x_safe_zone,
                             y_safe_zone, assembler);
  movement.TurnRight90();

  // Act
  movement.TurnLeft90();

  // Assert
  ASSERT_EQ(expected_heading, movement.GetCurrentHeadingFromAssembler());

  // Cleanup
  delete assembler;
}

// Boundary Check Tests
TEST(
    MovementTest,
    MovementTest_when_move_forward_called_with_heading_up_and_y_location_is_less_than_ceiling_cap_expect_y_location_to_be_ceiling_cap) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 1;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  int expected_y_location = 1;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(y_start_location, x_start_location, y_safe_zone,
                             x_safe_zone, assembler);

  // Act
  movement.MoveForward();

  // Assert
  ASSERT_EQ(expected_y_location, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_forward_called_with_heading_down_and_y_location_is_greater_than_y_safe_zone_expect_y_location_to_be_y_safe_zone) {
  // Arrange
  int x_start_location = 5;
  int y_start_location = 10;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  int expected_y_location = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(y_start_location, x_start_location, y_safe_zone,
                             x_safe_zone, assembler);

  movement.TurnRight90();
  movement.TurnRight90();

  // Act
  movement.MoveForward();

  // Assert
  ASSERT_EQ(expected_y_location, movement.GetYLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_forward_called_with_heading_left_and_x_location_is_less_than_ceiling_cap_expect_x_location_to_be_ceiling_cap) {
  // Arrange
  int x_start_location = 1;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  int expected_x_location = 1;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(y_start_location, x_start_location, y_safe_zone,
                             x_safe_zone, assembler);

  movement.TurnLeft90();

  // Act
  movement.MoveForward();

  // Assert
  ASSERT_EQ(expected_x_location, movement.GetXLocation());

  // Cleanup
  delete assembler;
}

TEST(
    MovementTest,
    MovementTest_when_move_forward_called_with_heading_right_and_x_location_is_greater_than_x_safe_zone_expect_x_location_to_be_x_safe_zone) {
  // Arrange
  int x_start_location = 10;
  int y_start_location = 5;
  int x_safe_zone = 10;
  int y_safe_zone = 10;
  int expected_x_location = 10;

  CharacterAssembler *assembler = new CharacterAssembler();

  auto movement = PDMovement(y_start_location, x_start_location, y_safe_zone,
                             x_safe_zone, assembler);

  movement.TurnRight90();

  // Act
  movement.MoveForward();

  // Assert
  ASSERT_EQ(expected_x_location, movement.GetXLocation());

  // Cleanup
  delete assembler;
}