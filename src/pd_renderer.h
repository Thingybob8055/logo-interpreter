#ifndef PD_RENDERER_H_
#define PD_RENDERER_H_

#include <curses.h>

typedef struct PDRendererStruct PDRender;

struct PDRendererStruct *CreateRenderer(WINDOW *window, int start_y_coordinate,
                                      int start_x_coordinate,
                                      char *leading_character);
void DestroyPDRenderStruct(struct PDRendererStruct *obj);

struct PDRendererStruct {
  int x_location, y_location, x_safe_zone, y_safe_zone;
  char *leading_character;
  WINDOW *current_window;
  int last_command;
};

#endif /* PD_RENDERER_H_ */