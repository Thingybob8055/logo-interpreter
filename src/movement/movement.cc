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

void Movement::MoveUp() {
  assembler->SetLeadingCharacter((char *)"▲");
  assembler->SetTrailingCharacter(KEY_UP, pen_position);
  assembler->SetLastCommand(KEY_UP);
  y_location--;
  BoundaryCheck();
}

void Movement::MoveDown() {
  assembler->SetLeadingCharacter((char *)"▼");
  assembler->SetTrailingCharacter(KEY_DOWN, pen_position);
  assembler->SetLastCommand(KEY_DOWN);
  y_location++;
  BoundaryCheck();
}

void Movement::MoveLeft() {
  assembler->SetLeadingCharacter((char *)"◀");
  assembler->SetTrailingCharacter(KEY_LEFT, pen_position);
  assembler->SetLastCommand(KEY_LEFT);
  x_location--;
  BoundaryCheck();
}

void Movement::MoveRight() {
  assembler->SetLeadingCharacter((char *)"▶");
  assembler->SetTrailingCharacter(KEY_RIGHT, pen_position);
  assembler->SetLastCommand(KEY_RIGHT);
  x_location++;
  BoundaryCheck();
}