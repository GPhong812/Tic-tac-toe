#include "board.h"

PositionCoordinates::PositionCoordinates() {
	positionID = 0;
	coordinates = std::make_pair(0, 0);
}

Board::Board() {
	for (int i = 0; i < 9; i++) {
		gameBoard[i] = EMPTY_SPACE;
		positionsOnBoard[i].positionID = i;
	}

	positionsOnBoard[0].coordinates = std::make_pair(50, 75);
	positionsOnBoard[1].coordinates = std::make_pair(160, 75);
	positionsOnBoard[2].coordinates = std::make_pair(270, 75);
	positionsOnBoard[3].coordinates = std::make_pair(50, 185);
	positionsOnBoard[4].coordinates = std::make_pair(160, 185);
	positionsOnBoard[5].coordinates = std::make_pair(270, 185);
	positionsOnBoard[6].coordinates = std::make_pair(50, 295);
	positionsOnBoard[7].coordinates = std::make_pair(160, 295);
	positionsOnBoard[8].coordinates = std::make_pair(270, 295);

}

Board::~Board() {

}

bool Board::isGameOver() {
	if (won() || boardIsFull())
		return true;
	else
		return false;
}

PositionCoordinates* Board::getPositionsOnBoard() {
	return positionsOnBoard;
}

char* Board::getGameBoard() {
	return gameBoard;
}

bool Board::won() {
	if (rowWin() || columnWin() || diagonalWin())
		return true;
	else
		return false;
}

// Checks if the three given chars are equal
bool Board::allEqual(char A, char B, char C) {
	if ((A != EMPTY_SPACE) && (A == B) && (B == C))
		return true;
	else
		return false;
}

bool Board::rowWin() {
	if (allEqual(gameBoard[0], gameBoard[1], gameBoard[2]))
		return true;

	if (allEqual(gameBoard[3], gameBoard[4], gameBoard[5]))
		return true;

	if (allEqual(gameBoard[6], gameBoard[7], gameBoard[8]))
		return true;

	return false;
}

bool Board::columnWin() {
	if (allEqual(gameBoard[0], gameBoard[3], gameBoard[6]))
		return true;

	if (allEqual(gameBoard[1], gameBoard[4], gameBoard[7]))
		return true;

	if (allEqual(gameBoard[2], gameBoard[5], gameBoard[8]))
		return true;
	return false; //placeholder
}

bool Board::diagonalWin() {
	if (leftDiagonalWin() || rightDiagonalWin())
		return true;
	else
		return false;
}

bool Board::leftDiagonalWin() {
	if (allEqual(gameBoard[6], gameBoard[4], gameBoard[2]))
		return true;
	else
		return false;
}

bool Board::rightDiagonalWin() {
	if (allEqual(gameBoard[8], gameBoard[4], gameBoard[0]))
		return true;
	else
		return false;
}

bool Board::boardIsFull() {
	for (int i = 0; i < 9; i++) {
		if (gameBoard[i] == EMPTY_SPACE)
			return false;
	}

	return true;
}

bool Board::isValidMove(int move) {
	if(gameBoard[move] == EMPTY_SPACE)
	    return true;
	else {
		//tell the position is already taken
		return false;
	}
}

void Board::makeMove(int move, char turn) {
	gameBoard[move] = turn;
}
