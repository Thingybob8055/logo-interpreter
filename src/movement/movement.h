#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include "character_assembler/character_assembler.h"
#include "heading.h"
#include "pen_position.h"

constexpr const char* UP_ARROW = (const char*)"▲";
constexpr const char* DOWN_ARROW = (const char*)"▼";
constexpr const char* LEFT_ARROW = (const char*)"◀";
constexpr const char* RIGHT_ARROW = (const char*)"▶";

class Movement {
 private:
  int x_location;
  int y_location;
  int x_safe_zone;
  int y_safe_zone;

  void BoundaryCheck();
  PenPosition pen_position = PEN_DOWN;

  CharacterAssembler* assembler;

 public:
  Movement(int y_location, int x_location, int y_safe_zone, int x_safe_zone,
           CharacterAssembler* assembler);

  void MoveForward();
  void MoveBackward();
  void TurnRight90();
  void TurnLeft90();

  int GetXLocation() const { return x_location; }
  int GetYLocation() const { return y_location; };
  PenPosition GetPenPosition() const { return pen_position; }
  int GetXSafeZone() const { return x_safe_zone; }
  int GetYSafeZone() const { return y_safe_zone; }
  void SetPenPosition(PenPosition pen_position) {
    this->pen_position = pen_position;
  }

  const char* GetLeadingCharacterFromAssembler() const {
    return assembler->GetLeadingCharacter();
  }
  const char* GetTrailingCharacterFromAssembler() const {
    return assembler->GetTrailingCharacter();
  }

  Direction GetLastDirectionFronAssembler() const {
    return assembler->GetLastDirection();
  }
  Heading GetLastHeadingFromAssembler() const {
    return assembler->GetLastHeading();
  }
  Heading GetCurrentHeadingFromAssembler() const {
    return assembler->GetCurrentHeading();
  }
};

#endif /* MOVEMENT_H_ */