#include "game/loading.hpp"
#include "game/menu.hpp"
#include "game/option.hpp"
#include "game/simulation.hpp"
#include "game/state.hpp"

static StateType currentState = StateType::none;

void initializeState() {
   switch (currentState) {
   case StateType::none:                                    break;
   case StateType::loading:    initializeLoadingState();    break;
   case StateType::menu:       initializeMenuState();       break;
   case StateType::option:     initializeOptionState();     break;
   case StateType::simulation: initializeSimulationState(); break;
   }
}

void deinitializeState() {
   switch (currentState) {
   case StateType::none:                                      break;
   case StateType::loading:    deinitializeLoadingState();    break;
   case StateType::menu:       deinitializeMenuState();       break;
   case StateType::option:     deinitializeOptionState();     break;
   case StateType::simulation: deinitializeSimulationState(); break;
   }
}

void updateState() {
   switch (currentState) {
   case StateType::none:                                break;
   case StateType::loading:    updateLoadingState();    break;
   case StateType::menu:       updateMenuState();       break;
   case StateType::option:     updateOptionState();     break;
   case StateType::simulation: updateSimulationState(); break;
   }
}

void renderState() {
   switch (currentState) {
   case StateType::none:                                break;
   case StateType::loading:    renderLoadingState();    break;
   case StateType::menu:       renderMenuState();       break;
   case StateType::option:     renderOptionState();     break;
   case StateType::simulation: renderSimulationState(); break;
   }
}

void changeState(StateType newState) {
   deinitializeState();
   currentState = newState;
   initializeState();
}
