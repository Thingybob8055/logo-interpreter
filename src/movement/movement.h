#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "character_assembler/character_assembler.h"
#include "pen_position.h"

class Movement {
 public:
  Movement(int y_location, int x_location, int y_safe_zone, int x_safe_zone,
           CharacterAssembler *assembler);
  void MoveUp();
  void MoveDown();
  void MoveLeft();
  void MoveRight();

  int GetXLocation() { return x_location; }
  int GetYLocation() { return y_location; };
  PenPosition GetPenPosition() { return pen_position; }
  int GetXSafeZone() { return x_safe_zone; }
  int GetYSafeZone() { return y_safe_zone; }
  void SetPenPosition(PenPosition pen_position) {
    this->pen_position = pen_position;
  }

  char *GetLeadingCharacterFromAssembler() {
    return assembler->GetLeadingCharacter();
  }
  char *GetTrailingCharacterFromAssembler() {
    return assembler->GetTrailingCharacter();
  }
  int GetLastCommandFromAssembler() { return assembler->GetLastCommand(); }

 private:
  int x_location;
  int y_location;
  int x_safe_zone;
  int y_safe_zone;

  void BoundaryCheck();
  PenPosition pen_position;

  CharacterAssembler *assembler;
};

#endif /* MOVEMENT_H_ */