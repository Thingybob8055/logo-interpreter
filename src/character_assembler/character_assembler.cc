#include "character_assembler.h"

#include <curses.h>

#include <cstdint>

CharacterAssembler::CharacterAssembler() {
  this->leading_character = (char *)"▲";
  this->trailing_character = (char *)"";
  this->last_heading = HEADING_UP;
  this->current_heading = HEADING_UP;
}

const char *CharacterAssembler::TrailingCharacter(Direction current_direction) {
  if (current_direction == FORWARDS && last_direction == FORWARDS) {
    if (current_heading == HEADING_RIGHT) {
      if (last_heading == HEADING_RIGHT) {
        return "─";
      } else if (last_heading == HEADING_UP) {
        return "┌";
      } else if (last_heading == HEADING_DOWN) {
        return "└";
      } else if (last_heading == HEADING_LEFT) {
        return "─";
      }
    } else if (current_heading == HEADING_LEFT) {
      if (last_heading == HEADING_LEFT) {
        return "─";
      } else if (last_heading == HEADING_UP) {
        return "┐";
      } else if (last_heading == HEADING_DOWN) {
        return "┘";
      } else if (last_heading == HEADING_RIGHT) {
        return "─";
      }
    } else if (current_heading == HEADING_UP) {
      if (last_heading == HEADING_UP) {
        return "│";
      } else if (last_heading == HEADING_LEFT) {
        return "└";
      } else if (last_heading == HEADING_RIGHT) {
        return "┘";
      } else if (last_heading == HEADING_DOWN) {
        return "│";
      }
    } else if (current_heading == HEADING_DOWN) {
      if (last_heading == HEADING_DOWN) {
        return "│";
      } else if (last_heading == HEADING_LEFT) {
        return "┌";
      } else if (last_heading == HEADING_RIGHT) {
        return "┐";
      } else if (last_heading == HEADING_UP) {
        return "│";
      }
    }
  } else if (current_direction == BACKWARDS && last_direction == BACKWARDS) {
    if (current_heading == HEADING_RIGHT) {
      if (last_heading == HEADING_RIGHT) {
        return "─";
      } else if (last_heading == HEADING_UP) {
        return "┘";
      } else if (last_heading == HEADING_DOWN) {
        return "┐";
      } else if (last_heading == HEADING_LEFT) {
        return "─";
      }
    } else if (current_heading == HEADING_LEFT) {
      if (last_heading == HEADING_LEFT) {
        return "─";
      } else if (last_heading == HEADING_UP) {
        return "└";
      } else if (last_heading == HEADING_DOWN) {
        return "┌";
      } else if (last_heading == HEADING_RIGHT) {
        return "─";
      }
    } else if (current_heading == HEADING_UP) {
      if (last_heading == HEADING_UP) {
        return "│";
      } else if (last_heading == HEADING_LEFT) {
        return "┐";
      } else if (last_heading == HEADING_RIGHT) {
        return "┌";
      } else if (last_heading == HEADING_DOWN) {
        return "│";
      }
    } else if (current_heading == HEADING_DOWN) {
      if (last_heading == HEADING_DOWN) {
        return "│";
      } else if (last_heading == HEADING_LEFT) {
        return "┘";
      } else if (last_heading == HEADING_RIGHT) {
        return "└";
      } else if (last_heading == HEADING_UP) {
        return "│";
      }
    }
  } else if (current_direction == FORWARDS && last_direction == BACKWARDS) {
    if (current_heading == HEADING_RIGHT) {
      if (last_heading == HEADING_RIGHT) {
        return "─";
      } else if (last_heading == HEADING_UP) {
        return "└";
      } else if (last_heading == HEADING_DOWN) {
        return "┌";
      } else if (last_heading == HEADING_LEFT) {
        return "─";
      }
    } else if (current_heading == HEADING_LEFT) {
      if (last_heading == HEADING_LEFT) {
        return "─";
      } else if (last_heading == HEADING_UP) {
        return "┘";
      } else if (last_heading == HEADING_DOWN) {
        return "┐";
      } else if (last_heading == HEADING_RIGHT) {
        return "─";
      }
    } else if (current_heading == HEADING_UP) {
      if (last_heading == HEADING_UP) {
        return "│";
      } else if (last_heading == HEADING_LEFT) {
        return "┘";
      } else if (last_heading == HEADING_RIGHT) {
        return "└";
      } else if (last_heading == HEADING_DOWN) {
        return "│";
      }
    } else if (current_heading == HEADING_DOWN) {
      if (last_heading == HEADING_DOWN) {
        return "│";
      } else if (last_heading == HEADING_LEFT) {
        return "┐";
      } else if (last_heading == HEADING_RIGHT) {
        return "┌";
      } else if (last_heading == HEADING_UP) {
        return "│";
      }
    }
  } else if (current_direction == BACKWARDS && last_direction == FORWARDS) {
    if (current_heading == HEADING_RIGHT) {
      if (last_heading == HEADING_RIGHT) {
        return "─";
      } else if (last_heading == HEADING_UP) {
        return "┐";
      } else if (last_heading == HEADING_DOWN) {
        return "┘";
      } else if (last_heading == HEADING_LEFT) {
        return "─";
      }
    } else if (current_heading == HEADING_LEFT) {
      if (last_heading == HEADING_LEFT) {
        return "─";
      } else if (last_heading == HEADING_UP) {
        return "┌";
      } else if (last_heading == HEADING_DOWN) {
        return "└";
      } else if (last_heading == HEADING_RIGHT) {
        return "─";
      }
    } else if (current_heading == HEADING_UP) {
      if (last_heading == HEADING_UP) {
        return "│";
      } else if (last_heading == HEADING_LEFT) {
        return "┌";
      } else if (last_heading == HEADING_RIGHT) {
        return "┐";
      } else if (last_heading == HEADING_DOWN) {
        return "│";
      }
    } else if (current_heading == HEADING_DOWN) {
      if (last_heading == HEADING_DOWN) {
        return "│";
      } else if (last_heading == HEADING_LEFT) {
        return "└";
      } else if (last_heading == HEADING_RIGHT) {
        return "┘";
      } else if (last_heading == HEADING_UP) {
        return "│";
      }
    }
  }

  return " ";
}

void CharacterAssembler::SetTrailingCharacter(Direction current_direction,
                                              PenPosition pen_position) {
  if (pen_position == PEN_DOWN) {
    this->trailing_character = (char *)TrailingCharacter(current_direction);
  } else {
    this->trailing_character = (char *)" ";
  }
}