#include "box/rl_box.h"

#include <gtest/gtest.h>

#include "external/fff.h"

FAKE_VOID_FUNC(BeginDrawingWrapper);
FAKE_VOID_FUNC(ClearBackgroundWrapper, Color);
FAKE_VOID_FUNC(DrawRectangleLinesExWrapper, Rectangle, float, Color);
FAKE_VOID_FUNC(DrawTextWrapper, const char*, int, int, int, Color);
FAKE_VOID_FUNC(EndDrawingWrapper);
FAKE_VALUE_FUNC(RenderTexture2D, LoadRenderTextureWrapper, int, int);
FAKE_VOID_FUNC(BeginTextureModeWrapper, RenderTexture2D);
FAKE_VOID_FUNC(EndTextureModeWrapper);
FAKE_VOID_FUNC(DrawTextureProWrapper, Texture2D, Rectangle, Rectangle,
               Vector2, float, Color);

TEST(RLBoxTest, CreateBox_from_constructor) {
  RLWindow window;
  RLBox box;
  ASSERT_EQ(BeginDrawingWrapper_fake.call_count, 1);
  ASSERT_EQ(ClearBackgroundWrapper_fake.call_count, 1);
  ASSERT_EQ(DrawRectangleLinesExWrapper_fake.call_count, 1);
  ASSERT_EQ(DrawTextWrapper_fake.call_count, 1);
  ASSERT_EQ(EndDrawingWrapper_fake.call_count, 1);
  ASSERT_EQ(LoadRenderTextureWrapper_fake.call_count, 1);
  ASSERT_EQ(BeginTextureModeWrapper_fake.call_count, 1);
  ASSERT_EQ(EndTextureModeWrapper_fake.call_count, 1);
  ASSERT_EQ(DrawTextureProWrapper_fake.call_count, 1);
}

TEST(RLBoxTest, GetXSafeZone) {
  RLWindow window;
  RLBox box;
  ASSERT_EQ(box.GetXSafeZone(), 0);
}

TEST(RLBoxTest, GetYSafeZone) {
  RLWindow window;
  RLBox box;
  ASSERT_EQ(box.GetYSafeZone(), 0);
}