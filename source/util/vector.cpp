#include "util/vector.hpp"

float getWindowWidth() {
   return (float)GetScreenWidth();
}

float getWindowHeight() {
   return (float)GetScreenHeight();
}

Vector2 getWindowSize() {
   return {(float)GetScreenWidth(), (float)GetScreenHeight()};
}

Vector2 getWindowCenter() {
   return {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
}
