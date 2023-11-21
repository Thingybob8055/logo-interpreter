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

  const char *GetLeadingCharacter() const { return leading_character; }
  const char *GetTrailingCharacter() const { return trailing_character; }

  void SetLeadingCharacter(const char *leading_character) {
    this->leading_character = leading_character;
  }
  void SetTrailingCharacter(const char *trailing_character) {
    this->trailing_character = trailing_character;
  }

  void SetLastDirection(Direction direction) { last_direction = direction; }
  Direction GetLastDirection() const { return last_direction; }

  void SetLastHeading(Heading heading) { last_heading = heading; }
  Heading GetLastHeading() const { return last_heading; }

  void SetCurrentHeading(Heading heading) { current_heading = heading; }
  Heading GetCurrentHeading() const { return current_heading; }

 private:
  const char *TrailingCharacter(Direction current_direction);
  const char *TrailingCharacterIfCurrentAndLastDirectionIsForwards() const;
  const char *TrailingCharacterIfCurrentAndLastDirectionIsBackwards() const;
  const char *TrailingCharacterIfCurrentDirectionIsForwardsLastIsBackwards()
      const;
  const char *TrailingCharacterIfCurrentDirectionIsBackwardsLastIsForwards()
      const;
  const char *leading_character = static_cast<const char *>("▲");
  const char *trailing_character = static_cast<const char *>("");

  Direction last_direction;
  Heading last_heading;
  Heading current_heading;
};

#endif /* CHARACTER_ASSEMBLER_H_ */