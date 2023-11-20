#include <cstdint>

#include "box/pd_box.h"
#include "character_assembler/character_assembler.h"
#include "importer/file_importer.h"
#include "movement/movement.h"
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
    graphics->Move(command, 5);
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
  auto *box = new PDBox(window);
  box->CreateBox();

  uint8_t start_y_coordinate = box->GetYSafeZone() / 2;
  uint8_t start_x_coordinate = box->GetXSafeZone() / 2;
  CharacterAssembler *assembler = new CharacterAssembler();
  Movement *movement =
      new Movement(start_y_coordinate, start_x_coordinate, box->GetYSafeZone(),
                   box->GetXSafeZone(), assembler);
  auto *graphics = new PDRenderer(window, movement);
  RunLoop(window, graphics);

  FreeMemory(window, graphics);
  delete movement;

  return 0;
}
