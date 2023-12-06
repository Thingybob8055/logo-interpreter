#include "raylib_wrapper.h"

WRAPPER_FUNCTION(void, InitWindow, int, width, int, height, const char *, title)

WRAPPER_FUNCTION(void, SetTargetFPS, int, fps)

WRAPPER_FUNCTION(void, BeginDrawing)

WRAPPER_FUNCTION(void, ClearBackground, Color, color)

WRAPPER_FUNCTION(void, DrawRectangleLinesEx, Rectangle, rec, float, lineThick,
                 Color, color)

WRAPPER_FUNCTION(void, DrawText, const char *, text, int, posX, int, posY, int,
                 fontSize, Color, color)

WRAPPER_FUNCTION(void, EndDrawing)

WRAPPER_FUNCTION(RenderTexture2D, LoadRenderTexture, int, width, int, height)

WRAPPER_FUNCTION(void, BeginTextureMode, RenderTexture2D, target)

WRAPPER_FUNCTION(void, DrawTexturePro, Texture2D, texture, Rectangle, sourceRec,
                 Rectangle, destRec, Vector2, origin, float, rotation, Color,
                 tint)

WRAPPER_FUNCTION(void, EndTextureMode)

WRAPPER_FUNCTION(bool, WindowShouldClose)

WRAPPER_FUNCTION(void, CloseWindow)

WRAPPER_FUNCTION(Texture2D, LoadTexture, const char *, fileName)

WRAPPER_FUNCTION(void, DrawRectangleV, Vector2, position, Vector2, size, Color,
                 color)

WRAPPER_FUNCTION(float, sinf, float, value)

WRAPPER_FUNCTION(float, cosf, float, value)

WRAPPER_FUNCTION(unsigned char *, rlReadScreenPixels, int, width, int, height)

WRAPPER_FUNCTION(bool, SaveFileData, const char *, fileName, void *, data, int,
                 dataSize)

WRAPPER_FUNCTION(bool, IsKeyPressed, int, key)

WRAPPER_FUNCTION(Vector2, GetWindowScaleDPI)