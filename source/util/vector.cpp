#include "util/vector.hpp"

Vector2 getWindowSize() {
   return {(float)GetScreenWidth(), (float)GetScreenHeight()};
}

Vector2 getWindowCenter() {
   return {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
}

Vector2 getWindowCenterWithOffset(const Vector2 &offset) {
   return {GetScreenWidth() / 2.0f + offset.x, GetScreenHeight() / 2.0f + offset.y};
}

float getWindowWidth() {
   return (float)GetScreenWidth();
}

float getWindowHeight() {
   return (float)GetScreenHeight();
}

float getWindowWidthUnit() {
   return (float)GetScreenWidth() / 10.0f;
}

float getWindowHeightUnit() {
   return (float)GetScreenHeight() / 10.0f;
}

float getWindowSizeUnit() {
   int width = GetScreenWidth();
   int height = GetScreenHeight();
   return (width < height ? width / 10.0f : height / 10.0f);
}

float getWindowFontSize() {
   return getWindowSizeUnit();
}
