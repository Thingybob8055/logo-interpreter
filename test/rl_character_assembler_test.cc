#include "character_assembler/rl_character_assembler.h"

#include <gtest/gtest.h>

TEST(RLCharacterAssemblerTest,
     when_constructed_expect_rl_character_assembler_to_be_created) {
  RLCharacterAssembler assembler;
  EXPECT_EQ(assembler.GetCurrentHeading(), HEADING_UP);
  Color black = BLACK;
  EXPECT_EQ(assembler.GetTrailColour().a, black.a);
  EXPECT_EQ(assembler.GetTrailColour().b, black.b);
  EXPECT_EQ(assembler.GetTrailColour().g, black.g);
  EXPECT_EQ(assembler.GetTrailColour().r, black.r);
}

TEST(RLCharacterAssemblerTest,
     when_set_current_heading_expect_current_heading_to_be_updated) {
  RLCharacterAssembler assembler;
  assembler.SetCurrentHeading(HEADING_DOWN);
  EXPECT_EQ(assembler.GetCurrentHeading(), HEADING_DOWN);
}

TEST(RLCharacterAssemblerTest,
     when_set_trail_colour_expect_trail_colour_to_be_updated) {
  RLCharacterAssembler assembler;
  assembler.SetTrailColour(1);
  Color blue = BLUE;
  EXPECT_EQ(assembler.GetTrailColour().a, blue.a);
  EXPECT_EQ(assembler.GetTrailColour().b, blue.b);
  EXPECT_EQ(assembler.GetTrailColour().g, blue.g);
  EXPECT_EQ(assembler.GetTrailColour().r, blue.r);
}