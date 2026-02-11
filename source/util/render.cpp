#include "util/render.hpp"
#include "raylib.h"
#include "raymath.h"

void drawTextCentered(const char *text, const Vector2 &position, float fontSize, const Color &color) {
   DrawTextPro(GetFontDefault(), text, position, Vector2Scale(MeasureTextEx(GetFontDefault(), text, fontSize, 1.0f), 0.5f), 0.0f, fontSize, 1.0f, color);
}

void drawTextureCentered(const Texture &texture, const Vector2 &position, const Vector2 &size, float rotation, const Color &color) {
   DrawTexturePro(texture, {0.0f, 0.0f, (float)texture.width, (float)texture.height}, {position.x, position.y, size.x, size.y}, Vector2Scale(size, 0.5f), rotation, color);
}

void drawRectCentered(const struct Vector2 &position, const struct Vector2 &size, const struct Color &color) {
   DrawRectanglePro({position.x, position.y, size.x, size.y}, Vector2Scale(size, 0.5f), 0.0f, color);
}
