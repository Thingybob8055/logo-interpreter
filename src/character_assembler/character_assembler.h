#ifndef CHARACTER_ASSEMBLER_H_
#define CHARACTER_ASSEMBLER_H_

#include "curses.h"
#include "movement/pen_position.h"

class CharacterAssembler {
 public:
  CharacterAssembler();
  const char *TrailingCharacter(int current_command);
  void SetTrailingCharacter(int current_command, PenPosition pen_position);

  char *GetLeadingCharacter() { return leading_character; }
  char *GetTrailingCharacter() { return trailing_character; }
  int GetLastCommand() { return last_command; }
  // setters
  void SetLeadingCharacter(char *leading_character) {
    this->leading_character = leading_character;
  }
  void SetTrailingCharacter(char *trailing_character) {
    this->trailing_character = trailing_character;
  }
  void SetLastCommand(int last_command) { this->last_command = last_command; }

 private:
  int last_command;
  char *leading_character;
  char *trailing_character;
};

#endif /* CHARACTER_ASSEMBLER_H_ */