

#ifndef PLAY_H
#define PLAY_H

#include "gameState.h"
#include "texture.h"
#include "board.h"
#include "graphics.h"
#include "button.h"

class Play : public GameState {
private:
	//Images/Assets
	Texture background;
	Texture X;
	Texture O;
	Texture Message_TurnX;
	Texture Message_TurnO;
	Texture Message_WinnerX;
	Texture Message_WinnerO;
	Texture Message_Tie;


	Button buttons[TOTAL_POSITIONS];


	Board board;
	PositionCoordinates playerMove;
    char turn;
	bool gameOver;

	void setUpButtons(Graphics &graphics);
public:
	Play(Graphics &graphics);   //loads resources for gameplay
	~Play();  //frees resources
	int whichButtonWasPressed(); //returns ID of one of the 9 buttons (positions) on the game board if
	                        // a button was pressed
	void switchTurns();
	void declareWinner(Graphics &graphics);

	//Main loop functions
	void handleEvents(SDL_Event &e);
	void logic();
	void render(Graphics &graphics);
};

#endif //PLAY_H
