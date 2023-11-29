#include "renderer/rl_renderer.h"

#include <gtest/gtest.h>

#include "external/fff.h"
#include "fff_common.h"

FAKE_VOID_FUNC(BeginDrawingWrapper);
FAKE_VOID_FUNC(EndDrawingWrapper);
FAKE_VOID_FUNC(DrawTextureProWrapper, Texture2D, Rectangle, Rectangle, Vector2,
               float, Color);
FAKE_VOID_FUNC(DrawLineExWrapper, Vector2, Vector2, float, Color);

TEST(RLRendererTest, when_constructed_expect_rl_renderer_to_be_created) {
  RLBox box;
  RLRenderer renderer(&box, nullptr);
  EXPECT_NE(renderer.GetBox(), nullptr);
}

TEST(RLRendererTest, when_render_expect_used_raylib_wrappers_to_be_called) {
  reset_common_fakes();
  RLBox box;
  RLRenderer renderer(&box, nullptr);
  renderer.Render();
  EXPECT_EQ(DrawTextureProWrapper_fake.call_count, 2);
  EXPECT_EQ(BeginDrawingWrapper_fake.call_count, 1);
  EXPECT_EQ(EndDrawingWrapper_fake.call_count, 1);
  EXPECT_EQ(DrawTextWrapper_fake.call_count, 2);
  EXPECT_EQ(ClearBackgroundWrapper_fake.call_count, 2);
  EXPECT_EQ(DrawLineExWrapper_fake.call_count, 2);
  EXPECT_EQ(LoadRenderTextureWrapper_fake.call_count, 2);
  EXPECT_EQ(BeginTextureModeWrapper_fake.call_count, 2);
  EXPECT_EQ(EndTextureModeWrapper_fake.call_count, 2);
}

TEST(RLRendererTest, test_get_box) {
  RLRenderer renderer(nullptr, nullptr);
  renderer.Move(0, 0);
}