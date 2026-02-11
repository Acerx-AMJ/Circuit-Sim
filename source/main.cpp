#include "game/state.hpp"
#include "util/colors.hpp"
#include "raylib.h"

int main() {
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 600, "Circuit-Sim");
	SetExitKey(KEY_NULL);

	Image icon = LoadImage("assets/Circuit-SimIcon.png");
	SetWindowIcon(icon);
	UnloadImage(icon);

	changeState(StateType::menu);

	while (!WindowShouldClose()) {
		updateState();
		
		BeginDrawing();
		ClearBackground(C_BLACK);
		renderState();
		EndDrawing();
	}
}
