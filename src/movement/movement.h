#ifndef MOVEMENT_H_
#define MOVEMENT_H_

// #include "renderer/pd_renderer.h"

typedef enum PenPosition { PEN_UP, PEN_DOWN } PenPosition;

class Movement {
 public:
  Movement(int x_location, int y_location, int x_safe_zone, int y_safe_zone);
  Movement();
  void MoveUp();
  void MoveDown();
  void MoveLeft();
  void MoveRight();

  int GetXLocation() { return x_location; }
  int GetYLocation() { return y_location; };
  char *GetLeadingCharacter() { return leading_character; }
  char *GetTrailingCharacter() { return trailing_character; }
  PenPosition GetPenPosition() { return pen_position; }
  int GetXSafeZone() { return x_safe_zone; }
  int GetYSafeZone() { return y_safe_zone; }
  int GetLastCommand() { return last_command; }
  void SetPenPosition(PenPosition pen_position) {
    this->pen_position = pen_position;
  }

 private:
  int x_location;
  int y_location;
  int x_safe_zone;
  int y_safe_zone;

  void BoundaryCheck();
  const char *TrailingCharacter(int current_command);
  void SetTrailingCharacter(int current_command);
  int last_command;
  char *leading_character;
  char *trailing_character;
  PenPosition pen_position;
};

#endif /* MOVEMENT_H_ */