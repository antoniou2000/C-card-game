#include <iostream>
#include "GameBoard.h"

int main(){
	
	GameBoard game;
	
	game.initializeGameBoard();
	game.deckbuilder();
	game.printGameStatistics();
	game.gameplay();
	
}