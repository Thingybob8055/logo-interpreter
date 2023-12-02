#include "movement/rl_movement.h"

#include <gtest/gtest.h>

#include "character_assembler/rl_character_assembler.h"
#include "external/fff.h"
#include "fff_common.h"

class RLMovementTest : public ::testing::Test {
 protected:
  void SetUp() override { reset_common_fakes(); }
};

TEST_F(RLMovementTest, when_constructed_expect_rl_movement_to_be_created) {
  int x_location = 50;
  int y_location = 50;
  int x_safe_zone = 50;
  int y_safe_zone = 50;
  RLCharacterAssembler assembler;

  RLMovement movement(x_location, y_location, x_safe_zone, y_safe_zone,
                      &assembler);
  EXPECT_EQ(movement.GetXLocation(), x_location);
  EXPECT_EQ(movement.GetYLocation(), y_location);
  EXPECT_EQ(movement.GetXSafeZone(), x_safe_zone);
  EXPECT_EQ(movement.GetYSafeZone(), y_safe_zone);
  EXPECT_EQ(movement.GetCurrentHeadingFromAssembler(), HEADING_UP);
}

TEST_F(RLMovementTest,
       when_move_forward_expect_x_and_y_location_to_be_updated) {
  int x_location = 50;
  int y_location = 50;
  int x_safe_zone = 50;
  int y_safe_zone = 50;
  RLCharacterAssembler assembler;

  RLMovement movement(x_location, y_location, x_safe_zone, y_safe_zone,
                      &assembler);
  movement.MoveForward();
  EXPECT_EQ(cosfWrapper_fake.call_count, 1);
  EXPECT_EQ(sinfWrapper_fake.call_count, 1);
}

TEST_F(RLMovementTest,
       when_move_backward_expect_x_and_y_location_to_be_updated) {
  int x_location = 50;
  int y_location = 50;
  int x_safe_zone = 50;
  int y_safe_zone = 50;
  RLCharacterAssembler assembler;

  RLMovement movement(x_location, y_location, x_safe_zone, y_safe_zone,
                      &assembler);
  movement.MoveBackward();
  EXPECT_EQ(cosfWrapper_fake.call_count, 1);
  EXPECT_EQ(sinfWrapper_fake.call_count, 1);
}

TEST_F(RLMovementTest, when_turn_right_90_expect_angle_to_be_updated) {
  int x_location = 50;
  int y_location = 50;
  int x_safe_zone = 50;
  int y_safe_zone = 50;
  RLCharacterAssembler assembler;

  RLMovement movement(x_location, y_location, x_safe_zone, y_safe_zone,
                      &assembler);
  movement.TurnRight90();
  EXPECT_EQ((int)movement.GetCurrentHeadingFromAssembler(), 360);
}

TEST_F(RLMovementTest, when_turn_left_90_expect_angle_to_be_updated) {
  int x_location = 50;
  int y_location = 50;
  int x_safe_zone = 50;
  int y_safe_zone = 50;
  RLCharacterAssembler assembler;

  RLMovement movement(x_location, y_location, x_safe_zone, y_safe_zone,
                      &assembler);
  movement.TurnLeft90();
  EXPECT_EQ((int)movement.GetCurrentHeadingFromAssembler(), 180);
}
