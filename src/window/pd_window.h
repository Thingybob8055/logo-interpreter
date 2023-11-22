#ifndef PD_WINDOW_H_
#define PD_WINDOW_H_

#include <curses.h>

#include <cstdint>
#include <iostream>

#include "window/window.h"

class PDWindow : public Window {
 private:
  WINDOW *window;
  int y_max_screen_coordinate;
  int x_max_screen_coordinate;

 public:
  PDWindow();
  ~PDWindow() override;
  int GetInput() override;

  WINDOW *GetWindow();
  int GetYMaxScreenCoordinate() const { return y_max_screen_coordinate; }
  int GetXMaxScreenCoordinate() const { return x_max_screen_coordinate; }
};

void InitXcurses();

#endif /* PD_WINDOW_H_ */
