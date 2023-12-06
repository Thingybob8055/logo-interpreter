#include "rl_character_assembler.h"

RLCharacterAssembler::RLCharacterAssembler() {
  this->current_heading = (int)HEADING_UP;
  this->trail_colour = trail_colour_array[0];
}