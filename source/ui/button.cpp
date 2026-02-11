#include "ui/button.hpp"
#include "util/colors.hpp"
#include "util/render.hpp"
#include "util/vector.hpp"
#include "raymath.h"

void Button::resize(float unitX, float unitY, float unitSizeX, float unitSizeY) {
   float unit = getWindowSizeUnit();
   size = {unit * unitSizeX, unit * unitSizeY};
   position = {unit * unitX, unit * unitY};
}

void Button::update() {
   hovering = CheckCollisionPointRec(GetMousePosition(), {position.x - size.x / 2.0f, position.y - size.y / 2.0f, size.x, size.y});
   clicked = hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

   if (hovering) {
      scale = fminf(scale + GetFrameTime(), 1.1f);
   } else {
      scale = fmaxf(scale - GetFrameTime(), 1.0f);
   }
}

void Button::updateBasedOnDropY(float dropY) {
   if (GetMousePosition().y <= dropY) {
      update();
   }
}

void Button::render() {
   const float normalizedScale = (size.x > size.y ? size.y * (1.0f - scale) : size.x * (1.0f - scale));
   const Vector2 newSize = Vector2SubtractValue(size, normalizedScale);
   
   drawRectCentered(position, Vector2AddValue(newSize, 4.0f), (hovering && !clicked ? Color C_WHITE : Color C_BLACK));
   drawRectCentered(position, newSize, (hovering && !clicked ? hoverColor : color));
   drawTextCentered(text, position, getWindowFontSize() * 0.4f, C_WHITE);
}
