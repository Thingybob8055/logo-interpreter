#include "main.h"

#include <gtest/gtest.h>

#include "external/fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(RunLoop, Window*, Renderer*, Parser*);
FAKE_VOID_FUNC(DrawLineExWrapper, Vector2, Vector2, float, Color);
FAKE_VALUE_FUNC(bool, WindowShouldCloseWrapper);

TEST(MainTest, RunLoop) {
  RunLoop(nullptr, nullptr, nullptr);
  ASSERT_EQ(RunLoop_fake.call_count, 1);
}