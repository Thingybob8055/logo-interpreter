#include "character_assembler/pd_character_assembler.h"

#include <curses.h>
#include <gtest/gtest.h>
#include <stdio.h>

TEST(PDCharacterAssemblerTest,
     when_constructor_called_expect_pd_character_assembler_to_be_created) {
  // Arrange

  // Act
  auto assembler = PDCharacterAssembler();

  // Assert
  ASSERT_STREQ("▲", assembler.GetLeadingCharacter());
  ASSERT_STREQ("", assembler.GetTrailingCharacter());
  ASSERT_EQ(HEADING_UP, assembler.GetLastHeading());
  ASSERT_EQ(HEADING_UP, assembler.GetCurrentHeading());
}