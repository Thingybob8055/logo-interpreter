#include "character_assembler.h"

#include <curses.h>

#include <cstdint>

CharacterAssembler::CharacterAssembler() {
  this->last_command = KEY_RIGHT;
  this->leading_character = (char *)"▶";
  this->trailing_character = (char *)"";
}

const char *CharacterAssembler::TrailingCharacter(int current_command) {
  if (current_command == KEY_DOWN) {
    if (this->last_command == KEY_RIGHT) {
      return "┐";
    } else if (this->last_command == KEY_LEFT) {
      return "┌";
    } else {
      return "│";
    }
  }

  if (current_command == KEY_UP) {
    if (this->last_command == KEY_RIGHT) {
      return "┘";
    } else if (this->last_command == KEY_LEFT) {
      return "└";
    } else {
      return "│";
    }
  }

  if (current_command == KEY_LEFT) {
    if (this->last_command == KEY_UP) {
      return "┐";
    } else if (this->last_command == KEY_DOWN) {
      return "┘";
    } else {
      return "─";
    }
  }

  if (current_command == KEY_RIGHT) {
    if (this->last_command == KEY_UP) {
      return "┌";
    } else if (this->last_command == KEY_DOWN) {
      return "└";
    } else {
      return "─";
    }
  }
  return " ";
}

void CharacterAssembler::SetTrailingCharacter(int current_command,
                                              PenPosition pen_position) {
  if (pen_position == PEN_DOWN) {
    this->trailing_character = (char *)TrailingCharacter(current_command);
  } else {
    this->trailing_character = (char *)" ";
  }
}