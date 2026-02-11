#include "game/menu.hpp"
#include "util/colors.hpp"
#include "util/math.hpp"
#include "util/render.hpp"
#include "util/vector.hpp"
#include "raylib.h"

// Constants

constexpr float finalLoadingTime = 1.25f;
constexpr float loadingTransitionTime = 1.5f;

// Members

static float loadingIconRotation;
static float finalLoadingTimer;
static float loadingTransitionTimer;
static bool finishedLoading;
static Texture2D loadingIcon;

// Initialization/Deinitialization

void initializeMenuState() {
   loadingIconRotation = 0.0f;
   finalLoadingTimer = 0.0f;
   loadingTransitionTimer = 0.0f;
   finishedLoading = false;
   loadingIcon = LoadTexture("assets/loading.png");
}

void deinitializeMenuState() {
   UnloadTexture(loadingIcon);
}

// Update/Rendering

void updateMenuState() {
   if (!finishedLoading) {
      // @TODO: load all schematics and what not
      finalLoadingTimer += GetFrameTime();
      loadingIconRotation += GetFrameTime() * 360.0f;

      if (finalLoadingTimer >= finalLoadingTime) {
         loadingTransitionTimer += GetFrameTime();
         finishedLoading = (loadingTransitionTimer >= loadingTransitionTime);
      }
      return;
   }
}

void renderMenuState() {
   float fontSize = getWindowFontSize();
   
   if (!finishedLoading) {
      float dropY = 0.0f;
      float unit = getWindowSizeUnit();
      
      if (loadingTransitionTimer != 0.0f) {
         dropY = easeInOutSine(loadingTransitionTimer / loadingTransitionTime) * getWindowHeight();
      }

      
      DrawRectangleV({0.0f, dropY}, getWindowSize(), C_DARK_GREEN);
      drawTextureCentered(loadingIcon, {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f + dropY}, {unit, unit}, loadingIconRotation, C_WHITE);
      drawTextCentered("Circuit-Sim", getWindowCenterWithOffset({0.0f, -1.25f * unit + dropY}), fontSize, C_WHITE);
      return;
   }
}
