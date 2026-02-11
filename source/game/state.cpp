#include "game/menu.hpp"
#include "game/option.hpp"
#include "game/simulation.hpp"
#include "game/tutorial.hpp"
#include "game/state.hpp"
#include <cstdlib>

static StateType currentState = StateType::none;

void initializeState() {
   switch (currentState) {
   case StateType::none:                                    break;
   case StateType::menu:       initializeMenuState();       break;
   case StateType::option:     initializeOptionState();     break;
   case StateType::simulation: initializeSimulationState(); break;
   case StateType::tutorial:   initializeTutorialState();   break;
   }
}

void deinitializeState() {
   switch (currentState) {
   case StateType::none:                                      break;
   case StateType::menu:       deinitializeMenuState();       break;
   case StateType::option:     deinitializeOptionState();     break;
   case StateType::simulation: deinitializeSimulationState(); break;
   case StateType::tutorial:   deinitializeTutorialState();   break;
   }
}

void updateState() {
   switch (currentState) {
   case StateType::none:                                break;
   case StateType::menu:       updateMenuState();       break;
   case StateType::option:     updateOptionState();     break;
   case StateType::simulation: updateSimulationState(); break;
   case StateType::tutorial:   updateTutorialState();   break;
   }
}

void renderState() {
   switch (currentState) {
   case StateType::none:                                break;
   case StateType::menu:       renderMenuState();       break;
   case StateType::option:     renderOptionState();     break;
   case StateType::simulation: renderSimulationState(); break;
   case StateType::tutorial:   renderTutorialState();   break;
   }
}

void changeState(StateType newState) {
   deinitializeState();
   currentState = newState;
   initializeState();
}

void exitGame() {
   deinitializeState();
   exit(0);
}
