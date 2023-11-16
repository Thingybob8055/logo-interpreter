#include "character_assembler/character_assembler.h"

#include <curses.h>
#include <gtest/gtest.h>
#include <stdio.h>

TEST(CharacterAssemblerTest,
     when_constructor_called_expect_character_assembler_to_be_created) {
  // Arrange

  // Act
  auto assembler = CharacterAssembler();

  // Assert
  ASSERT_STREQ("▶", assembler.GetLeadingCharacter());
  ASSERT_STREQ("", assembler.GetTrailingCharacter());
  ASSERT_EQ(KEY_RIGHT, assembler.GetLastCommand());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_up_expect_trailing_character_to_be_space) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetTrailingCharacter(KEY_RIGHT, PEN_UP);

  // Assert
  ASSERT_STREQ(" ", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_down_and_last_command_is_right_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetTrailingCharacter(KEY_DOWN, PEN_DOWN);

  // Assert
  ASSERT_STREQ("┐", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_down_and_last_command_is_left_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_LEFT);
  assembler.SetTrailingCharacter(KEY_DOWN, PEN_DOWN);

  // Assert
  ASSERT_STREQ("┌", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_down_and_last_command_is_not_left_or_right_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_UP);
  assembler.SetTrailingCharacter(KEY_DOWN, PEN_DOWN);

  // Assert
  ASSERT_STREQ("│", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_up_and_last_command_is_right_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetTrailingCharacter(KEY_UP, PEN_DOWN);

  // Assert
  ASSERT_STREQ("┘", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_up_and_last_command_is_left_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_LEFT);
  assembler.SetTrailingCharacter(KEY_UP, PEN_DOWN);

  // Assert
  ASSERT_STREQ("└", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_up_and_last_command_is_not_left_or_right_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_DOWN);
  assembler.SetTrailingCharacter(KEY_UP, PEN_DOWN);

  // Assert
  ASSERT_STREQ("│", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_left_and_last_command_is_up_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_UP);
  assembler.SetTrailingCharacter(KEY_LEFT, PEN_DOWN);

  // Assert
  ASSERT_STREQ("┐", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_left_and_last_command_is_down_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_DOWN);
  assembler.SetTrailingCharacter(KEY_LEFT, PEN_DOWN);

  // Assert
  ASSERT_STREQ("┘", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_left_and_last_command_is_not_up_or_down_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_RIGHT);
  assembler.SetTrailingCharacter(KEY_LEFT, PEN_DOWN);

  // Assert
  ASSERT_STREQ("─", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_right_and_last_command_is_up_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_UP);
  assembler.SetTrailingCharacter(KEY_RIGHT, PEN_DOWN);

  // Assert
  ASSERT_STREQ("┌", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_right_and_last_command_is_down_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_DOWN);
  assembler.SetTrailingCharacter(KEY_RIGHT, PEN_DOWN);

  // Assert
  ASSERT_STREQ("└", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_right_and_last_command_is_not_up_or_down_expect_corresponding_trailing_character_to_be_set) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetLastCommand(KEY_LEFT);
  assembler.SetTrailingCharacter(KEY_RIGHT, PEN_DOWN);

  // Assert
  ASSERT_STREQ("─", assembler.GetTrailingCharacter());
}

TEST(
    CharacterAssemblerTest,
    when_set_trailing_character_called_and_pen_is_down_and_current_command_is_not_up_down_left_or_right_expect_trailing_character_to_be_space) {
  // Arrange
  auto assembler = CharacterAssembler();

  // Act
  assembler.SetTrailingCharacter(0, PEN_DOWN);

  // Assert
  ASSERT_STREQ(" ", assembler.GetTrailingCharacter());
}