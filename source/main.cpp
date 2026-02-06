#include <raylib.h>

int main() {
	InitWindow(800, 600, "Circuit Simulation");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangle(50, 50, 50, 50, RED);
		EndDrawing();
	}
}
