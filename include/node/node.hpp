#ifndef NODE_NODE_HPP
#define NODE_NODE_HPP

#include "raylib.h"

enum class NodeType : char {
   none,
   input,
   output,
   transistorNPN,
   resistor
};

struct Node {
   void initialize(NodeType nodeType);
   
   void update();
   void render();

   Vector2 position;
   Vector2 size;
   bool dragging = false;

   NodeType type;
   bool on = false;
};

#endif
