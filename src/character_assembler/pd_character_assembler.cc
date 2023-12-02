#include "pd_character_assembler.h"

constexpr const char* horizontal = (const char*)"─";
constexpr const char* vertical = (const char*)"│";
constexpr const char* top_left = (const char*)"┌";
constexpr const char* top_right = (const char*)"┐";
constexpr const char* bottom_left = (const char*)"└";
constexpr const char* bottom_right = (const char*)"┘";
constexpr const char* space = (const char*)" ";

PDCharacterAssembler::PDCharacterAssembler() {
  this->last_heading = HEADING_UP;
  this->current_heading = HEADING_UP;
}

const char* PDCharacterAssembler::TrailingCharacter(
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

void PDCharacterAssembler::SetTrailingCharacter(Direction current_direction,
                                                PenPosition pen_position) {
  if (pen_position == PEN_DOWN) {
    this->trailing_character = TrailingCharacter(current_direction);
  } else {
    this->trailing_character = space;
  }
}

const char*
PDCharacterAssembler::TrailingCharacterIfCurrentAndLastDirectionIsForwards()
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
PDCharacterAssembler::TrailingCharacterIfCurrentAndLastDirectionIsBackwards()
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

const char* PDCharacterAssembler::
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

const char* PDCharacterAssembler::
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

const char* PDCharacterAssembler::ReturnTrailingCharacterFromLastHeading(
    Heading heading1, Heading heading2, Heading heading3, const char* output1,
    const char* output2, const char* output3,
    const char* output_default) const {
  return (last_heading == heading1)   ? output1
         : (last_heading == heading2) ? output2
         : (last_heading == heading3) ? output3
                                      : output_default;
}
