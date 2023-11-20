#include "movement.h"

#include <curses.h>

#include <cstdint>

Movement::Movement(int y_location, int x_location, int y_safe_zone,
                   int x_safe_zone, CharacterAssembler *assembler) {
  this->x_location = x_location;
  this->y_location = y_location;
  this->x_safe_zone = x_safe_zone;
  this->y_safe_zone = y_safe_zone;
  this->pen_position = PEN_DOWN;
  this->assembler = assembler;
}

void Movement::BoundaryCheck() {
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

void Movement::MoveForward() {
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

void Movement::MoveBackward() {
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

void Movement::TurnRight90() {
  // assembler->SetLastHeading(assembler->GetCurrentHeading());
  if (assembler->GetCurrentHeading() == HEADING_UP) {
    assembler->SetCurrentHeading(HEADING_RIGHT);
    assembler->SetLeadingCharacter((char *)"▶");
  } else if (assembler->GetCurrentHeading() == HEADING_DOWN) {
    assembler->SetCurrentHeading(HEADING_LEFT);
    assembler->SetLeadingCharacter((char *)"◀");
  } else if (assembler->GetCurrentHeading() == HEADING_LEFT) {
    assembler->SetCurrentHeading(HEADING_UP);
    assembler->SetLeadingCharacter((char *)"▲");
  } else if (assembler->GetCurrentHeading() == HEADING_RIGHT) {
    assembler->SetCurrentHeading(HEADING_DOWN);
    assembler->SetLeadingCharacter((char *)"▼");
  }
}

void Movement::TurnLeft90() {
  // assembler->SetLastHeading(assembler->GetCurrentHeading());
  if (assembler->GetCurrentHeading() == HEADING_UP) {
    assembler->SetCurrentHeading(HEADING_LEFT);
    assembler->SetLeadingCharacter((char *)"◀");
  } else if (assembler->GetCurrentHeading() == HEADING_DOWN) {
    assembler->SetCurrentHeading(HEADING_RIGHT);
    assembler->SetLeadingCharacter((char *)"▶");
  } else if (assembler->GetCurrentHeading() == HEADING_LEFT) {
    assembler->SetCurrentHeading(HEADING_DOWN);
    assembler->SetLeadingCharacter((char *)"▼");
  } else if (assembler->GetCurrentHeading() == HEADING_RIGHT) {
    assembler->SetCurrentHeading(HEADING_UP);
    assembler->SetLeadingCharacter((char *)"▲");
  }
}