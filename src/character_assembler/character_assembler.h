#ifndef CHARACTER_ASSEMBLER_H_
#define CHARACTER_ASSEMBLER_H_

#include "curses.h"
#include "movement/heading.h"
#include "movement/pen_position.h"

class CharacterAssembler {
 public:
  CharacterAssembler();

  void SetTrailingCharacter(Direction current_direction,
                            PenPosition pen_position);

  char *GetLeadingCharacter() { return leading_character; }
  char *GetTrailingCharacter() { return trailing_character; }

  void SetLeadingCharacter(char *leading_character) {
    this->leading_character = leading_character;
  }
  void SetTrailingCharacter(char *trailing_character) {
    this->trailing_character = trailing_character;
  }

  void SetLastDirection(Direction direction) { last_direction = direction; }
  Direction GetLastDirection() { return last_direction; }

  void SetLastHeading(Heading heading) { last_heading = heading; }
  Heading GetLastHeading() { return last_heading; }

  void SetCurrentHeading(Heading heading) { current_heading = heading; }
  Heading GetCurrentHeading() { return current_heading; }

 private:
  const char *TrailingCharacter(Direction current_direction);
  char *leading_character;
  char *trailing_character;

  Direction last_direction;
  Heading last_heading;
  Heading current_heading;
};

#endif /* CHARACTER_ASSEMBLER_H_ */