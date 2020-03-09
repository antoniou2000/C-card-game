#include "Player.h"

using namespace std;

unsigned short Player::playerCount = 0;
vector<Player*> Player::players;

Player::Player(string name): playerName(name),
	numberOfProvinces(4), itemsBought(0), followersBought(0),
	personalitiesBought(0), holdingsBought(0),
	attackPoints(0), defendPoints(0){

		playerCount++;
		players.push_back(this);

}

Player::~Player(){

	while(dynastyDeck.size()){
		delete dynastyDeck.back();
		dynastyDeck.pop_back();
	}

	while(fateDeck.size()){
		delete fateDeck.back();
		fateDeck.pop_back();
	}

	while(hand.size()){
		delete hand.back();
		hand.pop_back();
	}

	while(army.size()){
		delete army.back();
		army.pop_back();
	}

	while(holdings.size()){
		delete holdings.back();
		holdings.pop_back();
	}

	for(int i=0; i < 4; i++){
		if (provinces[i] != NULL)
			delete provinces[i];
	}

}

void Player::startingPhase(){

	if(!numberOfProvinces) return;

	cout << "====================================================\n";
	cout << "\tPLAYER \"" << playerName << "\" -- STARTING PHASE --\n";
	cout << "====================================================\n\n";

	untapEverything();
	drawFateCard();
	revealProvinces();
	printHand();
	printProvinces();

	printHoldings();

}

void Player::equipPhase(){

	if(!numberOfProvinces) return;

	cout << "=================================================\n";
	cout << "\tPLAYER \"" << playerName << "\" -- EQUIP PHASE --\n";
	cout << "=================================================\n\n";

	if( army.empty() ){
		cout << "Player \"" << playerName << "\" has no army, skip Equip Phase\n\n";
		return;
	}

	printHand();
	printArmy();
	buyFateCard();

}

void Player::battlePhase(){

	if(!numberOfProvinces) return;

	cout << "==================================================\n";
	cout << "\tPLAYER \"" << playerName << "\" -- BATTLE PHASE --\n";
	cout << "==================================================\n\n";

	if( army.empty() ){
		cout << "Player \"" << playerName << "\" has no army, skip Battle Phase\n\n";
		return;
	}

	attack();
	defend();

}

void Player::economyPhase(){

	if(!numberOfProvinces) return;

	cout << "===================================================\n";
	cout << "\tPLAYER \"" << playerName << "\" -- ECONOMY PHASE --\n";
	cout << "===================================================\n\n";

	printProvinces();
	buyProvince();

}

void Player::finalPhase(){

	if(!numberOfProvinces) return;

	cout << "=================================================\n";
	cout << "\tPLAYER \"" << playerName << "\" -- FINAL PHASE --\n";
	cout << "=================================================\n\n";

	discardSurplusFateCards();

	printGameStatistics();
	printHand();
	printProvinces();
	printArena();
	printHoldings();

	reset();

}

bool Player::checkWinningCondition(){

	if((playerCount == 1) && (numberOfProvinces > 0))
		return true;
	else
		return false;

}

string Player::getName() const{

	return playerName;

}
