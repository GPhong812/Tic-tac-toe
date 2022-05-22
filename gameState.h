// Class mieu ta tung state cua game (intro, title screen, game over screen, ...)

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SDL.h"

class Graphics;

enum GameStates {
	STATE_NULL,
	STATE_INTRO,
	STATE_TITLE,
	STATE_PLAY,
	STATE_GAME_OVER,
	STATE_EXIT,
};

//   Include intro, title screen, play, game over

class GameState {
protected:
	int nextStateID;
public:
	int getNextStateID() { return nextStateID; }
	void requestStateChange(int newStateID) { nextStateID = newStateID; }

	virtual void handleEvents(SDL_Event &e) = 0; //pure virtual
	virtual void logic() = 0;
	virtual void render(Graphics &graphics) = 0;
	virtual ~GameState() {};
};

#endif //GAME_STATE_H
