#include "main.h"

#include <gtest/gtest.h>

#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VOID_FUNC(RunLoop, Window*, Renderer*, Parser*);

TEST(MainTest, RunLoop) {
  RunLoop(nullptr, nullptr, nullptr);
  ASSERT_EQ(RunLoop_fake.call_count, 1);
}