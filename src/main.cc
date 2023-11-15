#include <cstdint>

#include "importer/file_importer.h"
#include "renderer/pd_renderer.h"
#include "window/pd_window.h"

bool GetExitCommand(int command) {
  if (command == 'x') {
    return true;
  } else {
    return false;
  }
}

void RunLoop(PDWindow *window, PDRenderer *graphics) {
  int command;
  while ((command = wgetch(window->GetWindow()))) {
    if (GetExitCommand(command)) {
      break;
    }
    graphics->Move(command);
    graphics->Render();
    wrefresh(window->GetWindow());
  }
}

void FreeMemory(PDWindow *window, PDRenderer *graphics) {
  endwin();
  delete window;
  delete graphics;
}

int main(int argc, char **argv) {

  FileImporter fileImporter = FileImporter("test.txt");
  std::cout << fileImporter.GetContents() << std::endl;

  auto *window = new PDWindow(argc, argv);

  uint8_t start_y_coordinate = 1;
  uint8_t start_x_coordinate = 1;
  auto *graphics =
      new PDRenderer(window, start_y_coordinate, start_x_coordinate,
                     (char *)"▶", KEY_RIGHT, PEN_DOWN);
  RunLoop(window, graphics);

  FreeMemory(window, graphics);

  return 0;
}
