
#ifndef TITLE_H
#define TITLE_H

#include "gameState.h"
#include "texture.h"

class Title : public GameState {
private:
	Texture titleScreen;
public:
	Title(Graphics &graphics);
	~Title();


	void handleEvents(SDL_Event &e);
	void logic();
	void render(Graphics &graphics);
};

#endif //TITLE_H
