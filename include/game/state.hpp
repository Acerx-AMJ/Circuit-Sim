#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

enum class StateType : char { none, menu, option, simulation, tutorial };

void initializeState();
void deinitializeState();

void updateState();
void renderState();

void changeState(StateType newState);
void exitGame();

#endif
