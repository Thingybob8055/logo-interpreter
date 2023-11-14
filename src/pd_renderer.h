#ifndef PD_RENDERER_H_
#define PD_RENDERER_H_

#include <curses.h>

#define KEY_SPACE 32

typedef enum PenPosition { PEN_UP, PEN_DOWN } PenPosition;

typedef struct PDRendererStruct PDRender;

const char *TrailingCharacter(struct PDRendererStruct *obj,
                              int current_command);
int Render(struct PDRendererStruct *obj);
void Move(struct PDRendererStruct *obj, int command);
void MoveUp(struct PDRendererStruct *obj);
void MoveDown(struct PDRendererStruct *obj);
void MoveLeft(struct PDRendererStruct *obj);
void MoveRight(struct PDRendererStruct *obj);
void SetTrailingCharacter(struct PDRendererStruct *obj, int current_command);
void BoundaryCheck(struct PDRendererStruct *obj);
struct PDRendererStruct *CreateRenderer(WINDOW *window, int start_y_coordinate,
                                        int start_x_coordinate,
                                        char *leading_character);
void DestroyPDRenderStruct(struct PDRendererStruct **obj);

struct PDRendererStruct {
  int x_location;
  int y_location;
  int x_safe_zone;
  int y_safe_zone;
  char *leading_character;
  char *trailing_character;
  PenPosition pen_position;
  WINDOW *current_window;
  int last_command;
};

#endif /* PD_RENDERER_H_ */