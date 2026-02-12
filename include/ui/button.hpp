#ifndef UI_BUTTON_HPP
#define UI_BUTTON_HPP

#include "raylib.h"

struct Button {
   void update();
   void updateBasedOnDropY(float dropY);
   void render();

   Vector2 position, size;
   Color color, hoverColor;
   const char *text;

   float scale = 1.0f;
   bool hovering = false;
   bool forceHover = false;
   bool clicked = false;
};

#endif
