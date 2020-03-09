#include "GameBoard.h"

using namespace std;

GameBoard::~GameBoard(){

	while(Players.size()){
		delete Players.back();
		Players.pop_back();
	}

}

void GameBoard::initializeGameBoard(){

	srand(time(NULL));

	cout << "Enter number of players: ";
	cin >> no_Players;

	for(int i=0; i < no_Players; i++){
		cout << "Enter name for Player " << i << ": ";
		string name;
		cin >> name;
		Players.push_back(new Player(name));
	}
	
}

void GameBoard::deckbuilder(){

	for(int i=0; i < no_Players; i++)
		Players.at(i)->DeckBuilder();

}

void GameBoard::printGameStatistics(){

	for(int i=0; i < no_Players; i++)
		Players.at(i)->printPlayer();

}

void GameBoard::gameplay(){

	while(1){

		for(int i=0; i < no_Players; i++)
			Players.at(i)->startingPhase();
		for(int i=0; i < no_Players; i++)
			Players.at(i)->equipPhase();
		for(int i=0; i < no_Players; i++)
			Players.at(i)->battlePhase();
		for(int i=0; i < no_Players; i++)
			Players.at(i)->economyPhase();
		for(int i=0; i < no_Players; i++)
			Players.at(i)->finalPhase();

		for(int i=0; i < no_Players; i++){
			if(Players.at(i)->checkWinningCondition()){
				cout << "Player " << Players.at(i)->getName() << " won the game\n";
				return;
			}
		}

	}

}
