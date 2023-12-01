#include "fff_common.h"

DEFINE_FAKE_VOID_FUNC(DrawTextWrapper, const char*, int, int, int, Color);
DEFINE_FAKE_VOID_FUNC(ClearBackgroundWrapper, Color);
DEFINE_FAKE_VOID_FUNC(DrawRectangleLinesExWrapper, Rectangle, float, Color);
DEFINE_FAKE_VALUE_FUNC(RenderTexture2D, LoadRenderTextureWrapper, int, int);
DEFINE_FAKE_VOID_FUNC(BeginTextureModeWrapper, RenderTexture2D);
DEFINE_FAKE_VOID_FUNC(EndTextureModeWrapper);
DEFINE_FAKE_VALUE_FUNC(float, sinfWrapper, float);
DEFINE_FAKE_VALUE_FUNC(float, cosfWrapper, float);

void reset_common_fakes() {
  RESET_FAKE(DrawTextWrapper)
  RESET_FAKE(ClearBackgroundWrapper)
  RESET_FAKE(DrawRectangleLinesExWrapper)
  RESET_FAKE(LoadRenderTextureWrapper)
  RESET_FAKE(BeginTextureModeWrapper)
  RESET_FAKE(EndTextureModeWrapper)
  RESET_FAKE(sinfWrapper)
  RESET_FAKE(cosfWrapper)
}