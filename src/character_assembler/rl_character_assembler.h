#ifndef RL_CHARACTER_ASSEMBLER_H_
#define RL_CHARACTER_ASSEMBLER_H_

#include <vector>

#include "character_assembler/character_assembler.h"
#include "movement/pen_position.h"
#include "raylib_wrapper/raylib_wrapper.h"

class RLCharacterAssembler : public CharacterAssembler {
 public:
  RLCharacterAssembler();
  Heading GetCurrentHeading() const override {
    return (Heading)current_heading;
  }
  void SetCurrentHeading(Heading heading) override {
    current_heading = (int)heading;
  }

  Color GetTrailColour() const { return trail_colour; }
  void SetTrailColour(int index = 0) {
    this->trail_colour = trail_colour_array[index];
  }

 private:
  Color trail_colour_array[3] = {BLACK, BLUE, RED};
  int current_heading;
  Color trail_colour;
};

#endif /* RL_CHARACTER_ASSEMBLER_H_ */