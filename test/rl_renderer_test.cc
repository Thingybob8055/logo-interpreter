#include "renderer/rl_renderer.h"

#include <gtest/gtest.h>

#include "external/fff.h"
#include "fff_common.h"
#include "movement/pen_position.h"

FAKE_VOID_FUNC(BeginDrawingWrapper);
FAKE_VOID_FUNC(EndDrawingWrapper);
FAKE_VOID_FUNC(DrawTextureProWrapper, Texture2D, Rectangle, Rectangle, Vector2,
               float, Color);
FAKE_VALUE_FUNC(Texture2D, LoadTextureWrapper, const char *);
FAKE_VOID_FUNC(DrawRectangleVWrapper, Vector2, Vector2, Color);

class RLRendererTest : public ::testing::Test {
 protected:
  void SetUp() override { reset_common_fakes(); }
};

TEST_F(RLRendererTest, when_constructed_expect_rl_renderer_to_be_created) {
  RLBox box;
  RLRenderer renderer(&box, nullptr);
  EXPECT_NE(renderer.GetBox(), nullptr);
}

TEST_F(RLRendererTest, when_render_expect_used_raylib_wrappers_to_be_called) {
  RLBox box;
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement);
  renderer.Move(259, 2);
  renderer.Render();
  EXPECT_EQ(DrawTextureProWrapper_fake.call_count, 3);
  EXPECT_EQ(BeginDrawingWrapper_fake.call_count, 1);
  EXPECT_EQ(EndDrawingWrapper_fake.call_count, 1);
  EXPECT_EQ(DrawTextWrapper_fake.call_count, 1);
  EXPECT_EQ(ClearBackgroundWrapper_fake.call_count, 2);
  EXPECT_EQ(LoadRenderTextureWrapper_fake.call_count, 2);
  EXPECT_EQ(BeginTextureModeWrapper_fake.call_count, 2);
  EXPECT_EQ(EndTextureModeWrapper_fake.call_count, 2);
  EXPECT_EQ(DrawRectangleVWrapper_fake.call_count, 1);
}

TEST_F(RLRendererTest, test_move_function_move_down) {
  RLBox box;
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement);
  renderer.Move(258, 2);
  EXPECT_EQ(sinfWrapper_fake.call_count, 2);
  EXPECT_EQ(cosfWrapper_fake.call_count, 2);
}

TEST_F(RLRendererTest, test_move_function_move_up) {
  RLBox box;
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement);
  renderer.Move(259, 2);
  EXPECT_EQ(sinfWrapper_fake.call_count, 2);
  EXPECT_EQ(cosfWrapper_fake.call_count, 2);
}

TEST_F(RLRendererTest, test_move_function_pen_position) {
  RLBox box;
  RLMovement movement(50, 50, 350, 350, nullptr);
  RLRenderer renderer(&box, &movement);
  renderer.Move(32, 2);
  EXPECT_EQ(movement.GetPenPosition(), PEN_UP);
}

TEST_F(RLRendererTest, test_move_function_turn_left) {
  RLBox box;
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement);
  renderer.Move(260, 2);
  EXPECT_EQ(movement.GetCurrentHeadingFromAssembler(), 268);
}

TEST_F(RLRendererTest, test_move_function_turn_right) {
  RLBox box;
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement);
  renderer.Move(261, 2);
  EXPECT_EQ(movement.GetCurrentHeadingFromAssembler(), 272);
}