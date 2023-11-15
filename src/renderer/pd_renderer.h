#ifndef PD_RENDERER_H_
#define PD_RENDERER_H_
#include "window/pd_window.h"

#define KEY_SPACE 32
typedef enum PenPosition { PEN_UP, PEN_DOWN } PenPosition;

class PDRenderer {
private:
  int x_location;
  int y_location;
  int x_safe_zone;
  int y_safe_zone;
  char *leading_character;
  char *trailing_character;
  PenPosition pen_position;
  PDWindow *current_window;
  int last_command;

  void MoveUp();
  void MoveDown();
  void MoveLeft();
  void MoveRight();
  const char *TrailingCharacter(int current_command);
  void SetTrailingCharacter(int current_command);
  void BoundaryCheck();

public:
  PDRenderer(PDWindow *window, int start_y_coordinate, int start_x_coordinate,
             char *leading_character, int starting_direction, PenPosition default_pen_position);

  void Move(int command);
  int Render();
  int GetYLocation() { return y_location; }
  int GetXLocation() { return x_location; }
  int GetYSafeZone() { return y_safe_zone; }
  int GetXSafeZone() { return x_safe_zone; }
  char *GetLeadingCharacter() { return leading_character; }
  char *GetTrailingCharacter() { return trailing_character; }
  PenPosition GetPenPosition() { return pen_position; }
};

#endif /* PD_RENDERER_H_ */