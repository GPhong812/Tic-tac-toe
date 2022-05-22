#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


class Texture;

class Graphics {
private:
	bool initSuccess;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Graphics();
	~Graphics();
	bool init();
	bool initSucceeded();
	void free(); //frees resources
	SDL_Renderer* getRenderer() const;

	void renderTexture(SDL_Texture* texture, SDL_Rect* destination); // SDL_RenderCopy

};

#endif //GRAHIPCS_H
