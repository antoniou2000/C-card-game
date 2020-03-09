#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "cards.h"

class Player{

	private:

		std::string playerName;

		static std::vector<Player*> players;
		static unsigned short playerCount;

		static const unsigned short MAX_HAND;

		//Data members
		std::vector<GreenCard*> fateDeck;
		std::vector<BlackCard*> dynastyDeck;

		std::vector<GreenCard*> hand;

		BlackCard* provinces[4];
		std::vector<BlackCard*> army;
		std::vector<BlackCard*> holdings;
		unsigned short numberOfProvinces;

		//BlackCard* Stronghold; -> TO PRWTO STOIXEIO TOU VECTOR HOLDINGS

		std::vector<BlackCard*> attacking; //temp for each round
		std::vector<BlackCard*> defending; //reset at final stage

		unsigned int attackPoints; //points of the attacking personalities
		unsigned int defendPoints; //points of the defending personalities + initial defense

		//Data members for statistics
		unsigned short itemsBought;
		unsigned short followersBought;
		unsigned short personalitiesBought;
		unsigned short holdingsBought;

		//Function members
		void untapEverything() const;
		void drawFateCard();
		void discardSurplusFateCards();
		void revealProvinces() const;

		void buyFateCard();
		void buyProvince();

		void attack();
		void defend();

		void printHand() const;
		void printProvinces() const;
		void printArmy() const;
		void printGameStatistics() const;
		void printArena() const;
		void printHoldings() const;

		//Extra function members
		void untapArmy() const;
		void untapHoldings() const;
		void reset();
		unsigned short getInitDefense() const;
		unsigned short getMoney() const;

		void DeckShuffle();


	public:

		Player(std::string);
		~Player();

		void DeckBuilder();

		void startingPhase();
		void equipPhase();
		void battlePhase();
		void economyPhase();
		void finalPhase();

		bool checkWinningCondition();

		std::string getName() const;
		void printPlayer() const;
		unsigned short getHonour() const;

};
