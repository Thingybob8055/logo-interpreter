#include "pd_renderer.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void SetTrailingCharacter(struct PDRendererStruct *obj) {
  if (obj->pen_position == PEN_DOWN) {
    obj->trailing_character = (char *)"─";
  } else {
    obj->trailing_character = (char *)" ";
  }
}

void BoundaryCheck(struct PDRendererStruct *obj) {
  static uint8_t ceiling_cap = 1;
  if (obj->y_location < ceiling_cap) {
    obj->y_location = ceiling_cap;
  } else if (obj->y_location > obj->y_safe_zone) {
    obj->y_location = obj->y_safe_zone;
  } else if (obj->x_location < ceiling_cap) {
    obj->x_location = ceiling_cap;
  } else if (obj->x_location > obj->x_safe_zone) {
    obj->x_location = obj->x_safe_zone;
  }
}

void MoveRight(struct PDRendererStruct *obj) {
  obj->leading_character = (char *)"▶";
  SetTrailingCharacter(obj);
  obj->last_command = KEY_RIGHT;
  obj->x_location++;
  BoundaryCheck(obj);
}

void Move(struct PDRendererStruct *obj, int command) {
  switch (command) {
    case KEY_UP:
      // TODO:
      break;
    case KEY_DOWN:
      // TODO:
      break;
    case KEY_LEFT:
      // TODO:
      break;
    case KEY_RIGHT:
      MoveRight(obj);
      break;
    case KEY_SPACE:
      if (obj->pen_position == PEN_DOWN) {
        obj->pen_position = PEN_UP;
      } else {
        obj->pen_position = PEN_DOWN;
      }
      break;
    default:
      break;
  }
}

int Render(struct PDRendererStruct *obj) {
  int return_value = OK;
  if (obj->last_command == KEY_RIGHT) {
    return_value |= mvwaddstr(obj->current_window, obj->y_location,
                              obj->x_location - 1, obj->trailing_character);
  }
  return_value |= mvwaddstr(obj->current_window, obj->y_location,
                            obj->x_location, obj->leading_character);
  return_value |= wrefresh(obj->current_window);
  return return_value;
}

void DestroyPDRenderStruct(struct PDRendererStruct *obj) {
  if (obj != NULL) {
    free(obj);
  }
}

struct PDRendererStruct *CreateRenderer(WINDOW *window, int start_y_coordinate,
                                        int start_x_coordinate,
                                        char *leading_character) {
  struct PDRendererStruct *obj =
      (struct PDRendererStruct *)malloc(sizeof(struct PDRendererStruct));

  if (obj != NULL) {
    int y_max_screen_coordinate;
    int x_max_screen_coordinate;
    obj->current_window = window;
    obj->x_location = start_x_coordinate;
    obj->y_location = start_y_coordinate;
    getmaxyx(obj->current_window, y_max_screen_coordinate,
             x_max_screen_coordinate);
    obj->x_safe_zone = x_max_screen_coordinate - 2;
    obj->y_safe_zone = y_max_screen_coordinate - 2;
    keypad(obj->current_window, true);
    obj->leading_character = leading_character;
    obj->trailing_character = (char *)"";
    obj->last_command = KEY_RIGHT;
    obj->pen_position = PEN_DOWN;
  }

  return obj;
}