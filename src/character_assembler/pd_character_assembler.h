#ifndef PD_CHARACTER_ASSEMBLER_H_
#define PD_CHARACTER_ASSEMBLER_H_

#include <cstdint>

#include "character_assembler/character_assembler.h"
#include "movement/pen_position.h"

class PDCharacterAssembler : public CharacterAssembler {
 private:
  const char *TrailingCharacter(Direction current_direction) const;
  const char *TrailingCharacterIfCurrentAndLastDirectionIsForwards() const;
  const char *TrailingCharacterIfCurrentAndLastDirectionIsBackwards() const;
  const char *TrailingCharacterIfCurrentDirectionIsForwardsLastIsBackwards()
      const;
  const char *TrailingCharacterIfCurrentDirectionIsBackwardsLastIsForwards()
      const;
  const char *ReturnTrailingCharacterFromLastHeading(
      Heading heading1, Heading heading2, Heading heading3, const char *output1,
      const char *output2, const char *output3,
      const char *output_default) const;

  const char *leading_character = static_cast<const char *>("▲");
  const char *trailing_character = static_cast<const char *>("");
  Direction last_direction;
  Heading last_heading;
  Heading current_heading;

 public:
  PDCharacterAssembler();

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

  void SetCurrentHeading(Heading heading) override {
    current_heading = heading;
  }
  Heading GetCurrentHeading() const override { return current_heading; }
};

#endif /* PD_CHARACTER_ASSEMBLER_H_ */