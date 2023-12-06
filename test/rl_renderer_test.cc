#define MSF_GIF_IMPL
#include "renderer/rl_renderer.h"

#include <gtest/gtest.h>

#include "external/fff.h"
#include "fff_common.h"
#include "movement/pen_position.h"
#include "recorder/rl_recorder.h"

FAKE_VOID_FUNC(BeginDrawingWrapper);
FAKE_VOID_FUNC(EndDrawingWrapper);
FAKE_VOID_FUNC(DrawTextureProWrapper, Texture2D, Rectangle, Rectangle, Vector2,
               float, Color);
FAKE_VALUE_FUNC(Texture2D, LoadTextureWrapper, const char *);
FAKE_VOID_FUNC(DrawRectangleVWrapper, Vector2, Vector2, Color);
FAKE_VALUE_FUNC(unsigned char *, rlReadScreenPixelsWrapper, int, int);
FAKE_VALUE_FUNC(bool, SaveFileDataWrapper, const char *, void *, int);
FAKE_VALUE_FUNC(bool, IsKeyPressedWrapper, int);
FAKE_VALUE_FUNC(Vector2, GetWindowScaleDPIWrapper);

FAKE_VALUE_FUNC(int, MsfGifBeginWrapper, MsfGifState *, int, int);
FAKE_VALUE_FUNC(int, MSfGifFrameWrapper, MsfGifState *, uint8_t *, int, int,
                 int);
FAKE_VALUE_FUNC(MsfGifResult, MsfGifEndWrapper, MsfGifState *);
FAKE_VOID_FUNC(MsfGifFreeWrapper, MsfGifResult);

class RLRendererTest : public ::testing::Test {
 protected:
  void SetUp() override { reset_common_fakes(); }
};

TEST_F(RLRendererTest, when_constructed_expect_rl_renderer_to_be_created) {
  RLWindow window;
  RLBox box = RLBox(&window);
  RLRecorder recorder = RLRecorder(&window);
  RLRenderer renderer(&box, nullptr, &recorder);
  EXPECT_NE(renderer.GetBox(), nullptr);
}

TEST_F(RLRendererTest, when_render_expect_used_raylib_wrappers_to_be_called) {
  RLWindow window;
  RLBox box = RLBox(&window);
  RLRecorder recorder = RLRecorder(&window);
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement, &recorder);
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
  RLWindow window;
  RLBox box = RLBox(&window);
  RLRecorder recorder = RLRecorder(&window);
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement, &recorder);
  renderer.Move(258, 2);
  EXPECT_EQ(sinfWrapper_fake.call_count, 2);
  EXPECT_EQ(cosfWrapper_fake.call_count, 2);
}

TEST_F(RLRendererTest, test_move_function_move_up) {
  RLWindow window;
  RLBox box = RLBox(&window);
  RLRecorder recorder = RLRecorder(&window);
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement, &recorder);
  renderer.Move(259, 2);
  EXPECT_EQ(sinfWrapper_fake.call_count, 2);
  EXPECT_EQ(cosfWrapper_fake.call_count, 2);
}

TEST_F(RLRendererTest, test_move_function_pen_position) {
  RLWindow window;
  RLBox box = RLBox(&window);
  RLRecorder recorder = RLRecorder(&window);
  RLMovement movement(50, 50, 350, 350, nullptr);
  RLRenderer renderer(&box, &movement, &recorder);
  renderer.Move(32, 2);
  EXPECT_EQ(movement.GetPenPosition(), PEN_UP);
}

TEST_F(RLRendererTest, test_move_function_turn_left) {
  RLWindow window;
  RLBox box = RLBox(&window);
  RLRecorder recorder = RLRecorder(&window);
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement, &recorder);
  renderer.Move(260, 2);
  EXPECT_EQ(movement.GetCurrentHeadingFromAssembler(), 268);
}

TEST_F(RLRendererTest, test_move_function_turn_right) {
  RLWindow window;
  RLBox box = RLBox(&window);
  RLRecorder recorder = RLRecorder(&window);
  RLCharacterAssembler assembler;
  RLMovement movement(50, 50, 350, 350, &assembler);
  RLRenderer renderer(&box, &movement, &recorder);
  renderer.Move(261, 2);
  EXPECT_EQ(movement.GetCurrentHeadingFromAssembler(), 272);
}