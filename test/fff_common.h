#ifndef FFF_COMMON_H_
#define FFF_COMMON_H_

#include "external/fff.h"
#include "raylib_wrapper/raylib_wrapper.h"

DECLARE_FAKE_VOID_FUNC(DrawTextWrapper, const char*, int, int, int, Color);
DECLARE_FAKE_VOID_FUNC(ClearBackgroundWrapper, Color);
DECLARE_FAKE_VOID_FUNC(DrawRectangleLinesExWrapper, Rectangle, float, Color);
DECLARE_FAKE_VALUE_FUNC(RenderTexture2D, LoadRenderTextureWrapper, int, int);
DECLARE_FAKE_VOID_FUNC(BeginTextureModeWrapper, RenderTexture2D);
DECLARE_FAKE_VOID_FUNC(EndTextureModeWrapper);

void reset_common_fakes();

#endif /* FFF_COMMON_H_ */