#include <curses.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pd_renderer.h"

void InitXcurses(int argc, char **argv) {
#ifdef XCURSES
  Xinitscr(argc, argv);
#else
  initscr();
#endif
  noecho();
  cbreak();
  curs_set(0);
}

void CreateDrawingZone(WINDOW *window, int box_y_character,
                       int box_x_character) {
  box(window, box_y_character, box_x_character);
  refresh();
  wrefresh(window);
}

void CreateWindow(WINDOW **window) {
  int y_max_screen_coordinate, x_max_screen_coordinate;
  getmaxyx(stdscr, y_max_screen_coordinate, x_max_screen_coordinate);

  uint8_t y_safe_zone = y_max_screen_coordinate - 1;
  uint8_t x_safe_zone = x_max_screen_coordinate - 2;
  uint8_t begin_y = 1;
  uint8_t begin_x = 1;
  uint8_t box_x_character = 0;
  uint8_t box_y_character = 0;
  *window = newwin(y_safe_zone, x_safe_zone, begin_y, begin_x);
  CreateDrawingZone(*window, box_y_character, box_x_character);
}

bool GetExitCommand(int command) {
  if (command == 'x') {
    return true;
  } else {
    return false;
  }
}

void RunLoop(WINDOW **window, PDRender **graphics) {
  int command;
  while (command = wgetch(*window)) {
    if (GetExitCommand(command)) {
      break;
    }
    wrefresh(*window);
  }
}

void FreeMemory(PDRender **graphics) {
  endwin();
  DestroyPDRenderStruct(*graphics);
}

int main(int argc, char **argv) {
  InitXcurses(argc, argv);
  WINDOW *window;
  CreateWindow(&window);

  uint8_t start_y_coordinate = 1;
  uint8_t start_x_coordinate = 1;
  PDRender *graphics = CreateRenderer(window, start_y_coordinate,
                                      start_x_coordinate, (char *)"▶");
  RunLoop(&window, &graphics);

  FreeMemory(&graphics);

  return 0;
}
