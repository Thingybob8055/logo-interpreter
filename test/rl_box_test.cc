#include "box/rl_box.h"

#include <gtest/gtest.h>

#include "external/fff.h"
#include "fff_common.h"

TEST(RLBoxTest, CreateBox_from_constructor) {
  reset_common_fakes();
  RLWindow window;
  RLBox box;
  ASSERT_EQ(ClearBackgroundWrapper_fake.call_count, 1);
  ASSERT_EQ(DrawRectangleLinesExWrapper_fake.call_count, 1);
  ASSERT_EQ(DrawTextWrapper_fake.call_count, 1);
  ASSERT_EQ(LoadRenderTextureWrapper_fake.call_count, 1);
  ASSERT_EQ(BeginTextureModeWrapper_fake.call_count, 1);
  ASSERT_EQ(EndTextureModeWrapper_fake.call_count, 1);
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