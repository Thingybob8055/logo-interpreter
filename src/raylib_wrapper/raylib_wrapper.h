#ifndef RAYLIB_WRAPPER_H_
#define RAYLIB_WRAPPER_H_

#include <raylib.h>

#ifdef TEST
#define WEAK_REF __attribute__((weak))
#else
#define WEAK_REF
#endif

void WEAK_REF InitWindowWrapper(int width, int height, const char *title);
void WEAK_REF SetTargetFPSWrapper(int fps);

void WEAK_REF BeginDrawingWrapper();
void WEAK_REF ClearBackgroundWrapper(Color color);
void WEAK_REF DrawRectangleLinesExWrapper(Rectangle rec, float lineThick,
                                          Color color);
void WEAK_REF DrawTextWrapper(const char *text, int posX, int posY,
                              int fontSize, Color color);

void WEAK_REF EndDrawingWrapper();

void WEAK_REF CloseWindowWrapper();

#endif /* RAYLIB_WRAPPER_H_ */