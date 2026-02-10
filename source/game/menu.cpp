#include "game/menu.hpp"
#include "util/colors.hpp"
#include "util/math.hpp"
#include "util/vector.hpp"
#include "raylib.h"

// Constants

constexpr float finalLoadingTime = 1.25f;
constexpr float loadingTransitionTime = 1.5f;

// Members

float finalLoadingTimer;
float loadingTransitionTimer;
bool finishedLoading;

// Initialization/Deinitialization

void initializeMenuState() {
   finalLoadingTimer = 0.0f;
   loadingTransitionTimer = 0.0f;
   finishedLoading = false;
}

void deinitializeMenuState() {

}

// Update/Rendering

void updateMenuState() {
   // Handle loading
   if (!finishedLoading) {
      // @TODO: load all schematics and what not
      finalLoadingTimer += GetFrameTime();

      if (finalLoadingTimer >= finalLoadingTime) {
         loadingTransitionTimer += GetFrameTime();
         finishedLoading = (loadingTransitionTimer >= loadingTransitionTime);
      }
      return;
   }

   // Handle menu
}

void renderMenuState() {
   // Render loading
   if (!finishedLoading) {
      if (loadingTransitionTimer == 0.0f) {
         DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), C_DARK_GRAY);
         return;
      }
      float dropY = easeInOutSine(loadingTransitionTimer / loadingTransitionTime) * getWindowHeight();
      DrawRectangleV({0.0f, dropY}, getWindowSize(), C_DARK_GRAY);
      return;
   }

   // Render menu
}
