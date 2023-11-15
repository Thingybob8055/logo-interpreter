#ifndef PD_WINDOW_H_
#define PD_WINDOW_H_

#include <cstdint>
#include <curses.h>

class PDWindow {
private:
  WINDOW *window;
  int y_max_screen_coordinate;
  int x_max_screen_coordinate;

public:
  PDWindow(int argc, char **argv);
  ~PDWindow();

  WINDOW *GetWindow();
  int GetYMaxScreenCoordinate() { return y_max_screen_coordinate; }
  int GetXMaxScreenCoordinate() { return x_max_screen_coordinate; }
};

#endif /* PD_WINDOW_H_ */
