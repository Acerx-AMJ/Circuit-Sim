#ifndef UTIL_VECTOR_HPP
#define UTIL_VECTOR_HPP

#include "raylib.h"

Vector2 getWindowSize();
Vector2 getWindowCenter();
Vector2 getWindowCenterWithOffset(const Vector2 &offset);

float getWindowWidth();
float getWindowHeight();
float getWindowWidthUnit();
float getWindowHeightUnit();
float getWindowSizeUnit();
float getWindowFontSize();

#endif
