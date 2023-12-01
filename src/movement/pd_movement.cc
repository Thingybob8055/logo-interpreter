#include "pd_movement.h"

PDMovement::PDMovement(int y_location, int x_location, int y_safe_zone,
                       int x_safe_zone, PDCharacterAssembler *assembler)
    : x_location(x_location),
      y_location(y_location),
      x_safe_zone(x_safe_zone),
      y_safe_zone(y_safe_zone),
      assembler(assembler) {}

void PDMovement::BoundaryCheck() {
  static uint8_t ceiling_cap = 1;
  if (y_location < ceiling_cap) {
    y_location = ceiling_cap;
  } else if (y_location > y_safe_zone) {
    y_location = y_safe_zone;
  } else if (x_location < ceiling_cap) {
    x_location = ceiling_cap;
  } else if (x_location > x_safe_zone) {
    x_location = x_safe_zone;
  }
}

void PDMovement::MoveForward() {
  if (assembler->GetCurrentHeading() == HEADING_UP) {
    y_location--;
  } else if (assembler->GetCurrentHeading() == HEADING_DOWN) {
    y_location++;
  } else if (assembler->GetCurrentHeading() == HEADING_LEFT) {
    x_location--;
  } else if (assembler->GetCurrentHeading() == HEADING_RIGHT) {
    x_location++;
  }
  assembler->SetTrailingCharacter(FORWARDS, pen_position);
  assembler->SetLastDirection(FORWARDS);
  assembler->SetLastHeading(assembler->GetCurrentHeading());
  BoundaryCheck();
}

void PDMovement::MoveBackward() {
  if (assembler->GetCurrentHeading() == HEADING_UP) {
    y_location++;
  } else if (assembler->GetCurrentHeading() == HEADING_DOWN) {
    y_location--;
  } else if (assembler->GetCurrentHeading() == HEADING_LEFT) {
    x_location++;
  } else if (assembler->GetCurrentHeading() == HEADING_RIGHT) {
    x_location--;
  }
  assembler->SetTrailingCharacter(BACKWARDS, pen_position);
  assembler->SetLastHeading(assembler->GetCurrentHeading());
  assembler->SetLastDirection(BACKWARDS);
  BoundaryCheck();
}

void PDMovement::TurnRight90() {
  if (assembler->GetCurrentHeading() == HEADING_UP) {
    assembler->SetCurrentHeading(HEADING_RIGHT);
    assembler->SetLeadingCharacter(RIGHT_ARROW);
  } else if (assembler->GetCurrentHeading() == HEADING_DOWN) {
    assembler->SetCurrentHeading(HEADING_LEFT);
    assembler->SetLeadingCharacter(LEFT_ARROW);
  } else if (assembler->GetCurrentHeading() == HEADING_LEFT) {
    assembler->SetCurrentHeading(HEADING_UP);
    assembler->SetLeadingCharacter(UP_ARROW);
  } else if (assembler->GetCurrentHeading() == HEADING_RIGHT) {
    assembler->SetCurrentHeading(HEADING_DOWN);
    assembler->SetLeadingCharacter(DOWN_ARROW);
  }
}

void PDMovement::TurnLeft90() {
  if (assembler->GetCurrentHeading() == HEADING_UP) {
    assembler->SetCurrentHeading(HEADING_LEFT);
    assembler->SetLeadingCharacter(LEFT_ARROW);
  } else if (assembler->GetCurrentHeading() == HEADING_DOWN) {
    assembler->SetCurrentHeading(HEADING_RIGHT);
    assembler->SetLeadingCharacter(RIGHT_ARROW);
  } else if (assembler->GetCurrentHeading() == HEADING_LEFT) {
    assembler->SetCurrentHeading(HEADING_DOWN);
    assembler->SetLeadingCharacter(DOWN_ARROW);
  } else if (assembler->GetCurrentHeading() == HEADING_RIGHT) {
    assembler->SetCurrentHeading(HEADING_UP);
    assembler->SetLeadingCharacter(UP_ARROW);
  }
}