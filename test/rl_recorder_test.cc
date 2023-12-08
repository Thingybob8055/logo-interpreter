#include "recorder/rl_recorder.h"

#include <gtest/gtest.h>

#include "curses.h"
#include "external/fff.h"
#include "fff_common.h"

FAKE_VALUE_FUNC(unsigned char *, rlReadScreenPixelsWrapper, int, int);
FAKE_VALUE_FUNC(bool, SaveFileDataWrapper, const char *, void *, int);
FAKE_VALUE_FUNC(bool, IsKeyPressedWrapper, int);
FAKE_VALUE_FUNC(Vector2, GetWindowScaleDPIWrapper);

FAKE_VALUE_FUNC(int, msf_gif_beginWrapper, MsfGifState *, int, int);
FAKE_VALUE_FUNC(int, msf_gif_frameWrapper, MsfGifState *, uint8_t *, int, int,
                int);
FAKE_VALUE_FUNC(MsfGifResult, msf_gif_endWrapper, MsfGifState *);
FAKE_VOID_FUNC(msf_gif_freeWrapper, MsfGifResult);
FAKE_VOID_FUNC(TakeScreenshotWrapper, const char *);

class RLRecorderTest : public ::testing::Test {
 protected:
  void SetUp() override { reset_common_fakes(); }
};

TEST_F(RLRecorderTest, when_constructed_except_rl_recorder_to_be_created) {
  RLWindow window;
  RLRecorder recorder(&window);
}

TEST_F(RLRecorderTest, when_InitRecording_function_to_be_tested) {
  RESET_FAKE(GetWindowScaleDPIWrapper);
  RESET_FAKE(msf_gif_beginWrapper);
  RLWindow window;
  RLRecorder recorder(&window);
  recorder.InitRecording();
  EXPECT_EQ(GetWindowScaleDPIWrapper_fake.call_count, 1);
  EXPECT_EQ(msf_gif_beginWrapper_fake.call_count, 1);
}

TEST_F(RLRecorderTest, when_StartRecording_function_to_be_tested) {
  RESET_FAKE(GetWindowScaleDPIWrapper);
  RESET_FAKE(rlReadScreenPixelsWrapper);
  RESET_FAKE(msf_gif_frameWrapper);
  RLWindow window;
  RLRecorder recorder(&window);
  recorder.InitRecording();

  for (int i = 0; i < 10; i++) {
    recorder.StartRecording();
  }

  EXPECT_EQ(GetWindowScaleDPIWrapper_fake.call_count, 2);
  EXPECT_EQ(rlReadScreenPixelsWrapper_fake.call_count, 1);
  EXPECT_EQ(msf_gif_frameWrapper_fake.call_count, 1);
}

bool IsKeyPressedWrapper_custom_value_fake(int key) { return true; }

TEST_F(RLRecorderTest, when_SaveRecording_function_to_be_tested) {
  RESET_FAKE(GetWindowScaleDPIWrapper);
  RESET_FAKE(rlReadScreenPixelsWrapper);
  RESET_FAKE(IsKeyPressedWrapper);
  RESET_FAKE(SaveFileDataWrapper);
  RESET_FAKE(msf_gif_freeWrapper);
  RESET_FAKE(msf_gif_freeWrapper);
  RESET_FAKE(TakeScreenshotWrapper);

  RLWindow window;
  RLRecorder recorder(&window);
  recorder.InitRecording();

  IsKeyPressedWrapper_fake.custom_fake = IsKeyPressedWrapper_custom_value_fake;

  for (int i = 0; i < 10; i++) {
    recorder.StartRecording();
  }

  recorder.SaveRecording();

  EXPECT_EQ(GetWindowScaleDPIWrapper_fake.call_count, 2);
  EXPECT_EQ(rlReadScreenPixelsWrapper_fake.call_count, 1);
  EXPECT_EQ(IsKeyPressedWrapper_fake.call_count, 2);
  EXPECT_EQ(msf_gif_endWrapper_fake.call_count, 1);
  EXPECT_EQ(SaveFileDataWrapper_fake.call_count, 1);
  EXPECT_EQ(msf_gif_endWrapper_fake.call_count, 1);
  EXPECT_EQ(TakeScreenshotWrapper_fake.call_count, 1);
}
