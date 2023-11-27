#include "main.h"

void RayLibDisableLogging() { SetTraceLogLevel(LOG_NONE); }

bool GetExitCommand(int command) {
  if (command == 'x') {
    return true;
  } else {
    return false;
  }
}

void RunLoop(Window *window, Renderer *graphics, Parser *parser) {
  while (parser->HasNext()) {
    parser->Next();
    int command = parser->GetCommand();
    int magnitude = parser->GetMagnitude();
#ifdef DEBUG
    std::cout << "Command: " << command << " Magnitude: " << magnitude
              << std::endl;
#endif
    graphics->Move(command, magnitude);
    graphics->Render();
  }
  window->GetInput();
}

bool CheckForArguments(int argc) {
  if (argc != 3) {
    std::cout << "Usage: ./main <filename> <pd/rl>" << std::endl;
    return false;
  }
  return true;
}

void CreatePDUI(Parser *parser) {
  std::unique_ptr<UIFactory> ui_factory = std::make_unique<PDFactory>();
  auto window = ui_factory->createWindow();
  auto box = ui_factory->createBox(window.get());

  uint8_t start_y_coordinate = (uint8_t)box->GetYSafeZone() / 2;
  uint8_t start_x_coordinate = (uint8_t)box->GetXSafeZone() / 2;
  auto assembler = std::make_unique<CharacterAssembler>();
  auto movement = std::make_unique<Movement>(
      start_y_coordinate, start_x_coordinate, box->GetYSafeZone(),
      box->GetXSafeZone(), assembler.get());
  auto graphics = ui_factory->createRenderer(window.get(), movement.get());
  RunLoop(window.get(), graphics.get(), parser);
}

void CreateRLUI() {
  float thickness = 3.0f;
  Vector2 start = {55.0f, 55.0f};
  Vector2 end = {100.0f, 100.0f};
  Vector2 start2 = {100.0f, 100.0f};
  Vector2 end2 = {100.0f, 200.0f};
  std::unique_ptr<UIFactory> ui_factory = std::make_unique<RLFactory>();
  auto window = ui_factory->createWindow();
  auto box = ui_factory->createBox();
  while (!WindowShouldClose()) {
    BeginDrawing();
    DrawText("Congrats! You created your first window!", 190, 200, 20,
             LIGHTGRAY);
    DrawLineEx(start, end, thickness, RED);
    DrawLineEx(start2, end2, thickness, RED);
    EndDrawing();
  }
}

#ifndef TEST
int main(int argc, char **argv) {
  if (!CheckForArguments(argc)) {
    return 1;
  }

  RayLibDisableLogging();

  auto fileImporter = FileImporter(argv[1]);
  auto parser = Parser(fileImporter.GetContents());

  if (strcmp(argv[2], "pd") == 0) {
    CreatePDUI(&parser);
  } else if (strcmp(argv[2], "rl") == 0) {
    CreateRLUI();
  }
  return 0;
}
#endif
