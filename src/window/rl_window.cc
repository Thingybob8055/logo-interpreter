#include "rl_window.h"

RLWindow::RLWindow() {
  InitWindowWrapper(screen_width, screen_height, window_title);
  SetTargetFPSWrapper(frames_per_second);
}

RLWindow::~RLWindow() { CloseWindowWrapper(); }

bool RLWindow::ShouldExit() { return WindowShouldCloseWrapper(); }
