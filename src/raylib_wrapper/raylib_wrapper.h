#ifndef RAYLIB_WRAPPER_H_
#define RAYLIB_WRAPPER_H_

#undef KEY_ENTER
#undef KEY_BACKSPACE
#undef KEY_UP
#undef KEY_DOWN
#undef KEY_LEFT
#undef KEY_RIGHT
#undef KEY_HOME
#undef KEY_END

#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>

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

RenderTexture2D WEAK_REF LoadRenderTextureWrapper(int width, int height);

void WEAK_REF BeginTextureModeWrapper(RenderTexture2D target);

void WEAK_REF EndTextureModeWrapper();

void WEAK_REF DrawTextureProWrapper(Texture2D texture, Rectangle source,
                                    Rectangle dest, Vector2 origin,
                                    float rotation, Color tint);

bool WEAK_REF WindowShouldCloseWrapper();
void WEAK_REF CloseWindowWrapper();

Texture2D WEAK_REF LoadTextureWrapper(const char *fileName);

void WEAK_REF DrawRectangleVWrapper(Vector2 position, Vector2 size,
                                    Color color);

float WEAK_REF sinfWrapper(float value);

float WEAK_REF cosfWrapper(float value);

unsigned char *rlReadScreenPixelsWrapper(int width, int height);

bool SaveFileDataWrapper(const char *fileName, void *data, int dataSize);

bool IsKeyPressedWrapper(int key);

Vector2 GetWindowScaleDPIWrapper();

#endif /* RAYLIB_WRAPPER_H_ */