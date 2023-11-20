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
  ASSERT_STREQ("▲", assembler.GetLeadingCharacter());
  ASSERT_STREQ("", assembler.GetTrailingCharacter());
  ASSERT_EQ(HEADING_UP, assembler.GetLastHeading());
  ASSERT_EQ(HEADING_UP, assembler.GetCurrentHeading());
}