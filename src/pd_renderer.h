#ifndef PD_RENDERER_H_
#define PD_RENDERER_H_

#include <curses.h>

typedef struct PDRendererStruct PDRender;

int Render(struct PDRendererStruct *obj);
void Move(struct PDRendererStruct *obj, int command);
void MoveRight(struct PDRendererStruct *obj);
void SetTrailingCharacter(struct PDRendererStruct *obj);
void BoundaryCheck(struct PDRendererStruct *obj);
struct PDRendererStruct *CreateRenderer(WINDOW *window, int start_y_coordinate,
                                        int start_x_coordinate,
                                        char *leading_character);
void DestroyPDRenderStruct(struct PDRendererStruct *obj);

struct PDRendererStruct {
  int x_location;
  int y_location;
  int x_safe_zone;
  int y_safe_zone;
  char *leading_character;
  char *trailing_character;
  WINDOW *current_window;
  int last_command;
};

#endif /* PD_RENDERER_H_ */