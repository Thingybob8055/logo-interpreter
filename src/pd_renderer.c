#include "pd_renderer.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
    int y_max_screen_coordinate, x_max_screen_coordinate;
    obj->current_window = window;
    obj->x_location = start_x_coordinate;
    obj->y_location = start_y_coordinate;
    getmaxyx(obj->current_window, y_max_screen_coordinate,
             x_max_screen_coordinate);
    obj->x_safe_zone = x_max_screen_coordinate - 2;
    obj->y_safe_zone = y_max_screen_coordinate - 2;
    keypad(obj->current_window, true);
    obj->leading_character = leading_character;
    obj->last_command = KEY_RIGHT;
  }

  return obj;
}