#ifndef PD_BOX_H_
#define PD_BOX_H_

#include "curses.h"
#include "window/pd_window.h"

class PDBox {
 private:
  int box_x_character = 0;
  int box_y_character = 0;
  int y_safe_zone;
  int x_safe_zone;
  PDWindow *pd_window;
  void CreateBox(WINDOW *window, int y_character, int x_character);

 public:
  explicit PDBox(PDWindow *window);
  int GetXSafeZone() const { return x_safe_zone; }
  int GetYSafeZone() const { return y_safe_zone; }
};

#endif /* PD_BOX_H_ */