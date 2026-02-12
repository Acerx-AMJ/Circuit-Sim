#include "game/simulation.hpp"
#include "node/node.hpp"

// Members

static Node node[4];

// Initialization/Deinitialization

void initializeSimulationState() {
   node[0].position = {0.0f, 0.0f};
   node[0].initialize(NodeType::transistorNPN);

   node[1].position = {100.0f, 100.0f};
   node[1].initialize(NodeType::resistor);

   node[2].position = {200.0f, 300.0f};
   node[2].initialize(NodeType::input);
   
   node[3].position = {400.0f, 100.0f};
   node[3].initialize(NodeType::output);
}

void deinitializeSimulationState() {

}

// Update/Rendering

void updateSimulationState() {
   for (Node &n: node) {
      n.update();
   }
}

void renderSimulationState() {
   for (Node &n: node) {
      n.render();
   }
}
