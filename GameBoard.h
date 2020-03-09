#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Player.h"

class GameBoard{
	
	private:
		unsigned short no_Players;
		std::vector<Player*> Players;
	
	public:
		~GameBoard();
	
		void initializeGameBoard();
		void deckbuilder();
		void printGameStatistics();
		void gameplay();
	
};