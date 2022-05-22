
#ifndef BOARD_H
#define BOARD_H

#include <utility> //STL
#include "SDL.h"

#define EMPTY_SPACE '*'
#define PLAYER_X 'x'
#define PLAYER_O 'o'


/*
   1|2|3
   -----
   4|5|6
   -----
   7|8|9
*/
enum BoardPositionIDs {
	POS_1,
	POS_2,
	POS_3,
	POS_4,
	POS_5,
	POS_6,
	POS_7,
	POS_8,
	POS_9,
	TOTAL_POSITIONS = 9,
	OUTSIDE_BOARD = -1,
};

struct PositionCoordinates {
	int positionID;
	std::pair <int, int> coordinates; //<x,y>
	PositionCoordinates();
};

class Board {
private:
	char gameBoard[9];
	PositionCoordinates positionsOnBoard[9];

public:
	Board();
	~Board();
	bool isGameOver();
	PositionCoordinates* getPositionsOnBoard();
	char* getGameBoard();

	// Checking if game is over
	bool won();
	bool allEqual(char A, char B, char C); //checks if the three chars, A, B, C, are equal
	bool rowWin();
	bool columnWin();

	bool diagonalWin();
	bool leftDiagonalWin();
	bool rightDiagonalWin();

	bool boardIsFull();

	bool isValidMove(int move);
	void makeMove(int move, char turn);

};

#endif //BOARD_H
