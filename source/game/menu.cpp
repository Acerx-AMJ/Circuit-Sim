#include "game/menu.hpp"
#include "game/state.hpp"
#include "ui/button.hpp"
#include "util/colors.hpp"
#include "util/math.hpp"
#include "util/render.hpp"
#include "util/vector.hpp"
#include "raylib.h"

// Constants

constexpr float finalLoadingTime = 1.25f;
constexpr float loadingTransitionTime = 1.5f;
constexpr size_t buttonCount = 4;

// Members

static float dropY;
static float loadingIconRotation;
static float finalLoadingTimer;
static float loadingTransitionTimer;
static bool finishedLoading;

static Texture2D loadingIcon;
static Button buttons[buttonCount];

// Initialization/Deinitialization

void initializeMenuState() {
   dropY = 0.0f;
   loadingIconRotation = 0.0f;
   finalLoadingTimer = 0.0f;
   loadingTransitionTimer = 0.0f;
   finishedLoading = false;
   loadingIcon = LoadTexture("assets/loading.png");

   buttons[0].text = "SELECT";
   buttons[1].text = "TUTORIAL";
   buttons[2].text = "OPTIONS";
   buttons[3].text = "QUIT";
   for (int i = 0; i < buttonCount; i++) {
      buttons[i].color = C_GREEN;
      buttons[i].hoverColor = C_LIGHT_GREEN;
   }
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
         dropY = easeInOutSine(loadingTransitionTimer / loadingTransitionTime) * getWindowHeight();
         finishedLoading = (loadingTransitionTimer >= loadingTransitionTime);
      } else {
         return;
      }
   }

   // Update main menu
   for (int i = 0; i < buttonCount; i++) {
      Button &button = buttons[i];
      button.resize(2.1f, 3.0f + i, 2.0f, 0.75f);
      button.updateBasedOnDropY(dropY);

      // Select circuits
      if (i == 0 && button.clicked) {
         changeState(StateType::simulation);
         return;
      }

      // Tutorial
      if (i == 1 && button.clicked) {
         changeState(StateType::tutorial);
         return;
      }

      // Options
      if (i == 2 && button.clicked) {
         changeState(StateType::option);
         return;
      }

      // Quit
      if (i == 3 && button.clicked) {
         exitGame();
      }
   }
}

void renderMenuState() {
   float fontSize = getWindowFontSize();
   float unit = getWindowSizeUnit();

   // Render the main menu
   if (loadingTransitionTimer > 0.0f) {
      DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), C_DARK_GRAY);
      DrawTextPro(GetFontDefault(), "Circuit-Sim", {unit, unit}, {0.0f, 0.0f}, 0.0f, fontSize, 1.0f, C_WHITE);
      for (int i = 0; i < buttonCount; i++) {
         buttons[i].render();
      }
   }

   if (!finishedLoading) {
      DrawRectangleV({0.0f, dropY}, getWindowSize(), C_DARK_GREEN);
      drawTextureCentered(loadingIcon, {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f + dropY}, {unit, unit}, loadingIconRotation, C_WHITE);
      drawTextCentered("Circuit-Sim", getWindowCenterWithOffset({0.0f, -1.25f * unit + dropY}), fontSize, C_WHITE);
   }
}
