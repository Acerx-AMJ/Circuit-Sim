#include "game/state.hpp"
#include "raylib.h"

int main() {
	InitWindow(800, 600, "Circuit Simulation");
	SetTargetFPS(60);

	Image icon = LoadImage("Circuit-SimIcon.png");
	SetWindowIcon(icon);
	UnloadImage(icon);

	changeState(StateType::loading);

	while (!WindowShouldClose()) {
		updateState();
		
		BeginDrawing();
		ClearBackground(BLACK);
		renderState();
		EndDrawing();
	}
}
