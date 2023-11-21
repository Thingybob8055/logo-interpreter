#include "character_assembler.h"

#include <curses.h>

#include <cstdint>

constexpr const char* horizontal = (const char*)"─";
constexpr const char* vertical = (const char*)"│";
constexpr const char* top_left = (const char*)"┌";
constexpr const char* top_right = (const char*)"┐";
constexpr const char* bottom_left = (const char*)"└";
constexpr const char* bottom_right = (const char*)"┘";
constexpr const char* space = (const char*)" ";

CharacterAssembler::CharacterAssembler() {
  this->last_heading = HEADING_UP;
  this->current_heading = HEADING_UP;
}

const char* CharacterAssembler::TrailingCharacter(Direction current_direction) {
  const char* returned_trailing_character;
  if (current_direction == FORWARDS && last_direction == FORWARDS) {
    returned_trailing_character =
        TrailingCharacterIfCurrentAndLastDirectionIsForwards();
  } else if (current_direction == BACKWARDS && last_direction == BACKWARDS) {
    returned_trailing_character =
        TrailingCharacterIfCurrentAndLastDirectionIsBackwards();
  } else if (current_direction == FORWARDS && last_direction == BACKWARDS) {
    returned_trailing_character =
        TrailingCharacterIfCurrentDirectionIsForwardsLastIsBackwards();
  } else if (current_direction == BACKWARDS && last_direction == FORWARDS) {
    returned_trailing_character =
        TrailingCharacterIfCurrentDirectionIsBackwardsLastIsForwards();
  } else {
    returned_trailing_character = space;
  }

  return returned_trailing_character;
}

void CharacterAssembler::SetTrailingCharacter(Direction current_direction,
                                              PenPosition pen_position) {
  if (pen_position == PEN_DOWN) {
    this->trailing_character = TrailingCharacter(current_direction);
  } else {
    this->trailing_character = space;
  }
}

const char*
CharacterAssembler::TrailingCharacterIfCurrentAndLastDirectionIsForwards()
    const {
  switch (current_heading) {
    case HEADING_RIGHT:
      return (last_heading == HEADING_RIGHT)  ? horizontal
             : (last_heading == HEADING_UP)   ? top_left
             : (last_heading == HEADING_DOWN) ? bottom_left
                                              : horizontal;
    case HEADING_LEFT:
      return (last_heading == HEADING_LEFT)   ? horizontal
             : (last_heading == HEADING_UP)   ? top_right
             : (last_heading == HEADING_DOWN) ? bottom_right
                                              : horizontal;
    case HEADING_UP:
      return (last_heading == HEADING_UP)      ? vertical
             : (last_heading == HEADING_LEFT)  ? bottom_left
             : (last_heading == HEADING_RIGHT) ? bottom_right
                                               : vertical;
    case HEADING_DOWN:
      return (last_heading == HEADING_DOWN)    ? vertical
             : (last_heading == HEADING_LEFT)  ? top_left
             : (last_heading == HEADING_RIGHT) ? top_right
                                               : vertical;
  }
  return space;
}

const char*
CharacterAssembler::TrailingCharacterIfCurrentAndLastDirectionIsBackwards()
    const {
  switch (current_heading) {
    case HEADING_RIGHT:
      return (last_heading == HEADING_RIGHT)  ? horizontal
             : (last_heading == HEADING_UP)   ? bottom_right
             : (last_heading == HEADING_DOWN) ? top_right
                                              : horizontal;
    case HEADING_LEFT:
      return (last_heading == HEADING_LEFT)   ? horizontal
             : (last_heading == HEADING_UP)   ? bottom_left
             : (last_heading == HEADING_DOWN) ? top_left
                                              : horizontal;
    case HEADING_UP:
      return (last_heading == HEADING_UP)      ? vertical
             : (last_heading == HEADING_LEFT)  ? top_right
             : (last_heading == HEADING_RIGHT) ? top_left
                                               : vertical;
    case HEADING_DOWN:
      return (last_heading == HEADING_DOWN)    ? vertical
             : (last_heading == HEADING_LEFT)  ? bottom_right
             : (last_heading == HEADING_RIGHT) ? bottom_left
                                               : vertical;
  }
  return space;
}

const char* CharacterAssembler::
    TrailingCharacterIfCurrentDirectionIsForwardsLastIsBackwards() const {
  switch (current_heading) {
    case HEADING_RIGHT:
      return (last_heading == HEADING_RIGHT)  ? horizontal
             : (last_heading == HEADING_UP)   ? bottom_left
             : (last_heading == HEADING_DOWN) ? top_left
                                              : horizontal;
    case HEADING_LEFT:
      return (last_heading == HEADING_LEFT)   ? horizontal
             : (last_heading == HEADING_UP)   ? bottom_right
             : (last_heading == HEADING_DOWN) ? top_right
                                              : horizontal;
    case HEADING_UP:
      return (last_heading == HEADING_UP)      ? vertical
             : (last_heading == HEADING_LEFT)  ? bottom_right
             : (last_heading == HEADING_RIGHT) ? bottom_left
                                               : vertical;
    case HEADING_DOWN:
      return (last_heading == HEADING_DOWN)    ? vertical
             : (last_heading == HEADING_LEFT)  ? top_right
             : (last_heading == HEADING_RIGHT) ? top_left
                                               : vertical;
  }
  return space;
}

const char* CharacterAssembler::
    TrailingCharacterIfCurrentDirectionIsBackwardsLastIsForwards() const {
  switch (current_heading) {
    case HEADING_RIGHT:
      return (last_heading == HEADING_RIGHT)  ? horizontal
             : (last_heading == HEADING_UP)   ? top_right
             : (last_heading == HEADING_DOWN) ? bottom_right
                                              : horizontal;
    case HEADING_LEFT:
      return (last_heading == HEADING_LEFT)   ? horizontal
             : (last_heading == HEADING_UP)   ? top_left
             : (last_heading == HEADING_DOWN) ? bottom_left
                                              : horizontal;
    case HEADING_UP:
      return (last_heading == HEADING_UP)      ? vertical
             : (last_heading == HEADING_LEFT)  ? top_left
             : (last_heading == HEADING_RIGHT) ? top_right
                                               : vertical;
    case HEADING_DOWN:
      return (last_heading == HEADING_DOWN)    ? vertical
             : (last_heading == HEADING_LEFT)  ? bottom_left
             : (last_heading == HEADING_RIGHT) ? bottom_right
                                               : vertical;
  }
  return space;
}