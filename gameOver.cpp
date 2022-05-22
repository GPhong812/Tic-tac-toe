#include "gameOver.h"

GameOver::GameOver(Graphics &graphics) {
	if (!gameOverScreen.loadFromFile(graphics, "images/Game Over.png"))
		printf("Failed to load Title Screen!\n");
	nextStateID = STATE_NULL;
}

GameOver::~GameOver() {
	gameOverScreen.free();
}

void GameOver::handleEvents(SDL_Event &e) {
	//While there's events to handle
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			requestStateChange(STATE_EXIT);
		}
		else if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_RETURN))
		{
			requestStateChange(STATE_PLAY);
		}
		else if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_BACKSPACE))
		{
			requestStateChange(STATE_TITLE);
		}
	}
}

void GameOver::logic() {
}

void GameOver::render(Graphics &graphics) {
    gameOverScreen.render(graphics, 0, 0);
}
