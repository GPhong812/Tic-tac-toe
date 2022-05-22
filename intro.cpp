#include "intro.h"

Intro::Intro(Graphics &graphics) {
	if (!introImage.loadFromFile(graphics, "images/intro.png"))
		printf("Failed to initialize Intro!\n");
	nextStateID = STATE_NULL;
}

Intro::~Intro() {
	introImage.free();
}

void Intro::handleEvents(SDL_Event &e) {
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			requestStateChange(STATE_EXIT);
		}
		else if ((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_RETURN))
		{
			requestStateChange(STATE_TITLE);
		}
	}
}

void Intro::logic() {
        //Wait for 2 seconds before showing title screen
        if ( SDL_GetTicks() >= 2000 ) {
                requestStateChange(STATE_TITLE);
        }
}

void Intro::render(Graphics &graphics) {
	//Show image
	introImage.render(graphics, 0, 0);
}
