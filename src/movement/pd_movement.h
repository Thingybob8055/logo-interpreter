#ifndef PD_MOVEMENT_H_
#define PD_MOVEMENT_H_

#include <cstdint>

#include "character_assembler/pd_character_assembler.h"
#include "heading.h"
#include "movement.h"
#include "pen_position.h"

constexpr const char* UP_ARROW = (const char*)"▲";
constexpr const char* DOWN_ARROW = (const char*)"▼";
constexpr const char* LEFT_ARROW = (const char*)"◀";
constexpr const char* RIGHT_ARROW = (const char*)"▶";

class PDMovement : public Movement {
 private:
  int x_location;
  int y_location;
  int x_safe_zone;
  int y_safe_zone;

  void BoundaryCheck();
  PenPosition pen_position = PEN_DOWN;

  PDCharacterAssembler* assembler;

 public:
  PDMovement(int y_location, int x_location, int y_safe_zone, int x_safe_zone,
             PDCharacterAssembler* assembler);

  void MoveForward() override;
  void MoveBackward() override;
  void TurnRight90() override;
  void TurnLeft90() override;

  float GetXLocation() const override { return (float)x_location; }
  float GetYLocation() const override { return (float)y_location; }
  PenPosition GetPenPosition() const override { return pen_position; }
  int GetXSafeZone() const { return x_safe_zone; }
  int GetYSafeZone() const { return y_safe_zone; }
  void SetPenPosition(PenPosition pen_position) override {
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
  Heading GetCurrentHeadingFromAssembler() const override {
    return assembler->GetCurrentHeading();
  }
};

#endif /* PD_MOVEMENT_H_ */