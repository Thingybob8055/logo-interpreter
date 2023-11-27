#include "raylib_wrapper.h"

/*
This creates a wrapper around raylib functions dynamically. This is done to
ensure that no syntax errors occur due to function wrapping and is done compile
time. We are wrapping raylib functions to enable us to unit test our code using
mocking frameworks. As these functions are all void functions, mocking allows us
to check if the functions are called and how many times they are called.
*/

// Create function arguments
#define ARGS_0() void
#define ARGS_1() void
#define ARGS_2(t1, v1) t1 v1
#define ARGS_4(t1, v1, t2, v2) t1 v1, t2 v2
#define ARGS_6(t1, v1, t2, v2, t3, v3) t1 v1, t2 v2, t3 v3
#define ARGS_8(t1, v1, t2, v2, t3, v3, t4, v4) t1 v1, t2 v2, t3 v3, t4 v4
#define ARGS_10(t1, v1, t2, v2, t3, v3, t4, v4, t5, v5) \
  t1 v1, t2 v2, t3 v3, t4 v4, t5 v5
#define ARGS_N(_10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0, N, ...) ARGS##N
#define ARGS(...)                                                        \
  ARGS_N(_0, ##__VA_ARGS__, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0) \
  (__VA_ARGS__)

// Pass arguments to function
#define PASS_0()
#define PASS_1()
#define PASS_2(t1, v1) v1
#define PASS_4(t1, v1, t2, v2) v1, v2
#define PASS_6(t1, v1, t2, v2, t3, v3) v1, v2, v3
#define PASS_8(t1, v1, t2, v2, t3, v3, t4, v4) v1, v2, v3, v4
#define PASS_10(t1, v1, t2, v2, t3, v3, t4, v4, t5, v5) v1, v2, v3, v4, v5
#define PASS_N(_10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0, N, ...) PASS##N
#define PASS(...)                                                        \
  PASS_N(_0, ##__VA_ARGS__, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0) \
  (__VA_ARGS__)

#define WRAPPER_FUNCTION(FUNC, ...) \
  void FUNC##Wrapper(ARGS(__VA_ARGS__)) { FUNC(PASS(__VA_ARGS__)); }

WRAPPER_FUNCTION(InitWindow, int, width, int, height, const char *, title)

WRAPPER_FUNCTION(SetTargetFPS, int, fps)

WRAPPER_FUNCTION(BeginDrawing)

WRAPPER_FUNCTION(ClearBackground, Color, color)

WRAPPER_FUNCTION(DrawRectangleLinesEx, Rectangle, rec, float, lineThick, Color,
                 color)

WRAPPER_FUNCTION(DrawText, const char *, text, int, posX, int, posY, int,
                 fontSize, Color, color)

WRAPPER_FUNCTION(EndDrawing)

WRAPPER_FUNCTION(CloseWindow)
