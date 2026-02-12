#include "node/node.hpp"
#include "util/colors.hpp"

void Node::initialize(NodeType nodeType) {
   type = nodeType;

   switch (type) {
   case NodeType::none: break;
   case NodeType::input:
   case NodeType::output:
      size = {75.0f, 75.0f};
      break;
   case NodeType::transistorNPN:
      size = {200.0f, 100.0f};
      break;
   case NodeType::resistor:
      size = {175.0f, 60.0f};
      break;
   }
}

void Node::update() {
   // Handle dragging
   if (!dragging) {
      dragging = IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), {position.x, position.y, size.x, size.y});
   }

   if (dragging && !IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      dragging = false;
   }

   if (dragging) {
      position.x += GetMouseDelta().x;
      position.y += GetMouseDelta().y;
   }
}

void Node::render() {
   switch (type) {
   case NodeType::none: break;
   case NodeType::input:
   case NodeType::output:
      DrawCircle(position.x + size.x * 0.5f, position.y + size.y * 0.5f, size.x * 0.5f, (on ? Color C_RED : Color C_DARK_GRAY));
      break;
   case NodeType::transistorNPN:
      DrawRectangleV(position, size, C_DARK_GRAY);
      DrawText("NPN", position.x, position.y, 30.0f, C_WHITE);
      break;
   case NodeType::resistor:
      DrawRectangleV(position, size, C_YELLOW);
      DrawText("220 OHMs", position.x, position.y, 30.0f, C_WHITE);
      break;
   }
}
