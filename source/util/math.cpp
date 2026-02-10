#include "util/math.hpp"
#include "raylib.h"
#include <cmath>

float easeInOutSine(float x) {
   return -(std::cos(PI * x) - 1.0f) / 2.0f;
}
