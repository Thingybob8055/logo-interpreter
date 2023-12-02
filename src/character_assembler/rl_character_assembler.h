#ifndef RL_CHARACTER_ASSEMBLER_H_
#define RL_CHARACTER_ASSEMBLER_H_

#include <vector>

#include "character_assembler/character_assembler.h"
#include "movement/pen_position.h"

class RLCharacterAssembler : public CharacterAssembler {
 public:
  RLCharacterAssembler();
  Heading GetCurrentHeading() const override {
    return (Heading)current_heading;
  }
  void SetCurrentHeading(Heading heading) override {
    current_heading = (int)heading;
  }

 private:
  int current_heading;
};

#endif /* RL_CHARACTER_ASSEMBLER_H_ */