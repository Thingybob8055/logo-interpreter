#ifndef PD_BOX_H_
#define PD_BOX_H_

#include "box/box.h"
#include "curses.h"
#include "window/pd_window.h"

class PDBox : public Box {
 private:
  int box_x_character = 0;
  int box_y_character = 0;
  int y_safe_zone;
  int x_safe_zone;
  PDWindow *pd_window;
  void CreateBox(WINDOW *window, int y_character, int x_character);

 public:
  explicit PDBox(PDWindow *window);
  ~PDBox() override = default;
  int GetXSafeZone() const override { return x_safe_zone; }
  int GetYSafeZone() const override { return y_safe_zone; }
  WINDOW *GetWindow() const { return pd_window->GetWindow(); }
};

#endif /* PD_BOX_H_ */