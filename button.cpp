#include "button.h"


Button::Button() {
	position.x = 0;
	position.y = 0;
	currentSpriteID = BUTTON_SPRITE_MOUSE_OUT;
	buttonWidth = 0;
	buttonHeight = 0;
}

Button::~Button() {
	buttonSpriteSheet.free();
}

void Button::loadTextureAndSprites(Graphics &graphics, char* fileName) {
	buttonSpriteSheet.loadFromFile(graphics, fileName);

	for (int i = 0; i < BUTTON_SPRITE_TOTAL; i++) {
		spriteClips[i].x = 0;
		spriteClips[i].y = i * buttonHeight;
		spriteClips[i].h = buttonHeight;
		spriteClips[i].w = buttonWidth;
	}
}

bool Button::buttonWasPressed() {
	if (currentSpriteID == BUTTON_SPRITE_MOUSE_DOWN) {
		return true;
	}
	else
		return false;
}

void Button::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
}

void Button::setDimensions(int width, int height) {
	buttonWidth = width;
	buttonHeight = height;
}

//Handles mouse event
void Button::handleEvent(SDL_Event &e) {
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
		if (!mouseInButton()) {
			currentSpriteID = BUTTON_SPRITE_MOUSE_OUT;
		}
		else {
			switch (e.type) {
			    case SDL_MOUSEMOTION:
				    currentSpriteID = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				    break;

			    case SDL_MOUSEBUTTONDOWN:
				    currentSpriteID = BUTTON_SPRITE_MOUSE_DOWN;
				    break;

			    case SDL_MOUSEBUTTONUP:
				    currentSpriteID = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				    break;
			}
		}

	}
}

bool Button::mouseInButton() {
	int x = 0, y = 0;
	SDL_GetMouseState(&x, &y);

	bool inside = true;

	if (x < position.x) {
		inside = false;
	}
	else if (x > position.x + buttonWidth) {
		inside = false;
	}
	else if (y < position.y) {
		inside = false;
	}
	else if (y > position.y + buttonHeight) {
		inside = false;
	}

	return inside;
}

void Button::render(Graphics &graphics) {
	SDL_Rect renderQuad = { position.x, position.y,
		                    buttonSpriteSheet.getWidth(), buttonSpriteSheet.getHeight() };

	renderQuad.w = spriteClips[currentSpriteID].w;
	renderQuad.h = spriteClips[currentSpriteID].h;

	//Render current button sprite to screen
	SDL_RenderCopyEx(graphics.getRenderer(), buttonSpriteSheet.getSDLTexture(), &spriteClips[currentSpriteID],
		             &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}
