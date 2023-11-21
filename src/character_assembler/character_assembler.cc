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

const char* CharacterAssembler::TrailingCharacter(
    Direction current_direction) const {
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
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_RIGHT, HEADING_UP, HEADING_DOWN, horizontal, top_left,
          bottom_left, horizontal);
    case HEADING_LEFT:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_LEFT, HEADING_UP, HEADING_DOWN, horizontal, top_right,
          bottom_right, horizontal);
    case HEADING_UP:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_UP, HEADING_LEFT, HEADING_RIGHT, vertical, bottom_left,
          bottom_right, vertical);
    case HEADING_DOWN:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_DOWN, HEADING_LEFT, HEADING_RIGHT, vertical, top_left,
          top_right, vertical);
  }
  return space;
}

const char*
CharacterAssembler::TrailingCharacterIfCurrentAndLastDirectionIsBackwards()
    const {
  switch (current_heading) {
    case HEADING_RIGHT:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_RIGHT, HEADING_UP, HEADING_DOWN, horizontal, bottom_right,
          top_right, horizontal);
    case HEADING_LEFT:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_LEFT, HEADING_UP, HEADING_DOWN, horizontal, bottom_left,
          top_left, horizontal);
    case HEADING_UP:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_UP, HEADING_LEFT, HEADING_RIGHT, vertical, top_right,
          top_left, vertical);
    case HEADING_DOWN:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_DOWN, HEADING_LEFT, HEADING_RIGHT, vertical, bottom_right,
          bottom_left, vertical);
  }
  return space;
}

const char* CharacterAssembler::
    TrailingCharacterIfCurrentDirectionIsForwardsLastIsBackwards() const {
  switch (current_heading) {
    case HEADING_RIGHT:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_RIGHT, HEADING_UP, HEADING_DOWN, horizontal, bottom_left,
          top_left, horizontal);
    case HEADING_LEFT:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_LEFT, HEADING_UP, HEADING_DOWN, horizontal, bottom_right,
          top_right, horizontal);
    case HEADING_UP:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_UP, HEADING_LEFT, HEADING_RIGHT, vertical, bottom_right,
          bottom_left, vertical);
    case HEADING_DOWN:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_DOWN, HEADING_LEFT, HEADING_RIGHT, vertical, top_right,
          top_left, vertical);
  }
  return space;
}

const char* CharacterAssembler::
    TrailingCharacterIfCurrentDirectionIsBackwardsLastIsForwards() const {
  switch (current_heading) {
    case HEADING_RIGHT:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_RIGHT, HEADING_UP, HEADING_DOWN, horizontal, top_right,
          bottom_right, horizontal);
    case HEADING_LEFT:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_LEFT, HEADING_UP, HEADING_DOWN, horizontal, top_left,
          bottom_left, horizontal);
    case HEADING_UP:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_UP, HEADING_LEFT, HEADING_RIGHT, vertical, top_left,
          top_right, vertical);
    case HEADING_DOWN:
      return ReturnTrailingCharacterFromLastHeading(
          HEADING_DOWN, HEADING_LEFT, HEADING_RIGHT, vertical, bottom_left,
          bottom_right, vertical);
  }
  return space;
}

const char* CharacterAssembler::ReturnTrailingCharacterFromLastHeading(
    Heading param2, Heading param3, Heading param4, const char* param5,
    const char* param6, const char* param7, const char* param8) const {
  return (last_heading == param2)   ? param5
         : (last_heading == param3) ? param6
         : (last_heading == param4) ? param7
                                    : param8;
}
