#include "box/rl_box.h"

#include <gtest/gtest.h>

#include "external/fff.h"
#include "fff_common.h"

class RLBoxTest : public ::testing::Test {
 protected:
  void SetUp() override { reset_common_fakes(); }
};

TEST_F(RLBoxTest, CreateBox_from_constructor) {
  RLWindow window;
  RLBox box;
  ASSERT_EQ(ClearBackgroundWrapper_fake.call_count, 1);
  ASSERT_EQ(DrawRectangleLinesExWrapper_fake.call_count, 1);
  ASSERT_EQ(DrawTextWrapper_fake.call_count, 1);
  ASSERT_EQ(LoadRenderTextureWrapper_fake.call_count, 1);
  ASSERT_EQ(BeginTextureModeWrapper_fake.call_count, 1);
  ASSERT_EQ(EndTextureModeWrapper_fake.call_count, 1);
}

TEST_F(RLBoxTest, GetXSafeZone) {
  RLWindow window;
  RLBox box;
  ASSERT_EQ(box.GetXSafeZone(), 0);
}

TEST_F(RLBoxTest, GetYSafeZone) {
  RLWindow window;
  RLBox box;
  ASSERT_EQ(box.GetYSafeZone(), 0);
}