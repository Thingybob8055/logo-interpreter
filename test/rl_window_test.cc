#include "window/rl_window.h"

#include <gtest/gtest.h>

#include "external/fff.h"

FAKE_VOID_FUNC(InitWindowWrapper, int, int, const char *);
FAKE_VOID_FUNC(SetTargetFPSWrapper, int);
FAKE_VOID_FUNC(CloseWindowWrapper);

TEST(RLWindowTest,
     when_constructed_expect_init_window_and_set_target_fps_called) {
  RLWindow window;
  ASSERT_EQ(InitWindowWrapper_fake.call_count, 1);
  ASSERT_EQ(SetTargetFPSWrapper_fake.call_count, 1);
}
