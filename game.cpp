#include "game.h"

Game::Game() {
	currentState = NULL;
	currentStateID = STATE_NULL;
	nextState = STATE_NULL;
}

Game::~Game() {
	graphics.free();
	delete currentState;
}

bool Game::initSucceeded() {
	if (graphics.initSucceeded())
		return true;
	else
		return false;
}

//Main game loop
void Game::gameLoop() {
	currentStateID = STATE_INTRO;
	nextState = STATE_NULL;
	currentState = new Intro(graphics);

	SDL_Event e;
	while (currentStateID != STATE_EXIT)
	{
                currentState->handleEvents(e);

                currentState->logic();

		nextState = currentState->getNextStateID();
		if(nextState != STATE_NULL)
                        changeState();
                currentState->render(graphics);
		draw();

	}
}

void Game::changeState() {
	//If next state needs to be changed
	if (nextState != STATE_NULL) {
		//Delete current state
		if (nextState != STATE_EXIT) {
			delete currentState;
		}
		switch (nextState) {
		        case STATE_TITLE:
				currentState = new Title(graphics);
				break;
			case STATE_PLAY:
				currentState = new Play(graphics);
				break;
			case STATE_GAME_OVER:
				currentState = new GameOver(graphics);
				break;
		}
		currentStateID = nextState;
		nextState = STATE_NULL;
	}
}

//Updates the screen
void Game::draw() {
	SDL_SetRenderDrawColor(graphics.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(graphics.getRenderer());

	currentState->render(graphics);

	SDL_RenderPresent(graphics.getRenderer());
}


