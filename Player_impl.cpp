#include "Player.h"

using namespace std;

const unsigned short Player::MAX_HAND = 6;

void Player::untapEverything() const{

	untapArmy();
	untapHoldings();

	cout << "Everything is untapped\n\n";

}

void Player::drawFateCard(){

	if(fateDeck.empty()){
		cout << "There are no more cards from the Fate Deck\n";
		return;
	}

	GreenCard* newFateCard = fateDeck.back();
	fateDeck.pop_back();
	hand.push_back(newFateCard);

}

void Player::discardSurplusFateCards(){

	if(hand.size() > MAX_HAND){
		cout << "You have more cards at hand than the max limit\n";
		printHand();
		cout << "Choose one to remove: ";

		unsigned short rem;
		cin >> rem;

		delete hand.at(rem);
		hand.erase(hand.begin()+rem);
	}

}

void Player::revealProvinces() const{

	for(int i = 0; i < 4; i++){
		if (provinces[i] != NULL) //AKA destroyed
			provinces[i]->reveal();
	}

}

void Player::buyFateCard(){

	cout << "Money: " << getMoney() << endl;
	cout << "Enter card to buy (7 for skip): ";
	int pos;
	cin >> pos;
	while (pos != 7){

		cout << endl;
		if(hand.at(pos)->get_cost() > getMoney()){
			cout << "Not enought money\n";
			cout << "BUYING FAILED\n";
		}
		else if(hand.at(pos)->get_minHonour() > getHonour()){
			cout << "Not enough honour\n";
			cout << "BUYING FAILED\n";
		}
		else{

			cout << "Choose personality to equip the card\n";
			int pers;
			cin >> pers;
			if(army.at(pers)->isFull(hand.at(pos)->type())){//s
				cout << "Personality doesn't have space for more "
					<< (!hand.at(pos)->type() ? "followers" : "items") << endl;
				cout << "Buying failed\n";
			}
			else{

				subMoney(holdings, hand.at(pos)->get_cost());

				GreenCard* bought = hand.at(pos);
				if(army.at(pers)->equip(bought, getMoney()))
					subMoney(holdings, bought->get_effectCost());
				hand.erase(hand.begin()+pos);

			}
		}

		printHand();
		printArmy();
		cout << "Money: " << getMoney() << endl;
		cout << "Enter another card (7 for skip): ";
		cin >> pos;

	}

}

void Player::buyProvince(){

	cout << "Money: " << getMoney() << endl;
	cout << "Enter card to buy (4 for skip): ";
	int pos;
	cin >> pos;
	while(pos != 4){

		cout << endl;
		if(provinces[pos]->get_cost() > getMoney()){
			cout << "Not enought money\n";
			cout << "BUYING FAILED\n";
		}
		else{

			subMoney(holdings, provinces[pos]->get_cost());
			provinces[pos]->tap();

			if(provinces[pos]->type() == PERSONALITY){
				army.push_back(provinces[pos]);
				personalitiesBought++;
			}
			else{
				holdings.push_back(provinces[pos]);
				holdingsBought++;
				make_chain(holdings);
			}

			if(dynastyDeck.empty()){
				cout << "No more cards from the Dynasty Deck\n";
				provinces[pos] = holdings.front();
			}
			else{
				provinces[pos] = dynastyDeck.back();
				dynastyDeck.pop_back();
			}

		}

		printProvinces();
		cout << "Money: " << getMoney() << endl;
		cout << "Enter another card (4 for skip): ";
		cin >> pos;

	}

}

void Player::attack(){

	printArmy();
	cout << "Enter a personality for the attack (Enter -1 to stop): ";

	int pos;
	cin >> pos;
	while (pos != -1){
		army.at(pos)->tap();
		attacking.push_back(army.at(pos));
		attackPoints += army.at(pos)->get_attack();
		army.erase(army.begin()+pos);
		printArmy();
		cout << "Enter another personality for the attack (-1 to stop): ";
		cin >> pos;
	}
	cout << endl;

	//No attacking personalities-> No attack
	if(attacking.empty())
		return;

	cout << "Attack Points: " << attackPoints << endl << endl;

	for(int i = 0; i < playerCount; i++){
		if(players.at(i) != this){
			cout << i << ":";
			players.at(i)->printPlayer();
		}
	}
	cout << "Enter player to attack: ";
	cin >> pos;
	Player* Defender = players.at(pos);

	Defender->printProvinces();
	cout << "Enter province to attack: ";
	cin >> pos;

	if(attackPoints - Defender->defendPoints > Defender->getInitDefense() ){

		//attacker wins -> province is destroyed
		cout << "Province destroyed!\n";

		if (provinces[pos] != Defender->holdings.front()) //aka the province is not empty
			delete Defender->provinces[pos];

		Defender->provinces[pos] = NULL; //the province is destroyed
		Defender->numberOfProvinces--;

		if(Defender->numberOfProvinces == 0)
			playerCount--;

		for(int i = 0; i < Defender->defending.size(); i++){
			Defender->defending.at(i)->kill_Card();
			delete Defender->defending.at(i);
		}
		if(!Defender->defending.empty())
			Defender->defending.clear();

	}
	else if(attackPoints > Defender->defendPoints){

		//defender loses his defending personalities while
		//attacker loses his followers (and maybe personalities)
		cout << "Province NOT destroyed\n";

		int def = Defender->defendPoints;

		for(int i = 0; i < Defender->defending.size(); i++){
			Defender->defending.at(i)->kill_Card();
			delete Defender->defending.at(i);
		}
		if(!Defender->defending.empty())
			Defender->defending.clear();

		bla(attacking, def);

	}
	else if(attackPoints == Defender->defendPoints){

		//If attack points == defense points then
		//the attacker loses their attacking personalities and
		//the defender loses theis defending personalities
		cout << "Province NOT destroyed\n";

		for(int i = 0; i < attacking.size(); i++){
			attacking.at(i)->kill_Card();
			delete attacking.at(i);
		}
		if(!attacking.empty())
			attacking.clear();

		for(int i = 0; i < Defender->defending.size(); i++){
			Defender->defending.at(i)->kill_Card();
			delete Defender->defending.at(i);
		}
		if(!Defender->defending.empty())
			Defender->defending.clear();

	}
	else{  //attackPoints < Defender->defendPoints

		cout << "Province NOT destroyed\n";

		int att = attackPoints;

		for(int i = 0; i < attacking.size(); i++){
			attacking.at(i)->kill_Card();
			delete attacking.at(i);
		}
		if(!attacking.empty())
			attacking.clear();

		bla(Defender->defending, att);

	}
}

void Player::defend(){

	for(int i = 0; i < army.size(); i++){

		if((army.at(i)->get_isTapped() == false) && (army.at(i)->get_isDead() == false)){
			army.at(i)->tap();
			defending.push_back(army.at(i));
			defendPoints += army.at(i)->get_defense();
			army.erase(army.begin()+i);
		}

	}

	cout << "Player \"" << playerName << "\" has defense: " << defendPoints << endl;

}

void Player::printHand() const{

	cout << "Printing hand:\n";
	for (int i = 0; i < hand.size(); i++){
		cout << i << " : ";
		hand.at(i)->print();
		cout << endl;
	}

}

void Player::printProvinces() const{

	cout << "Printing Provinces:\n";

	for(int i = 0; i < 4; i++){
		cout << i << " : ";
		if(provinces[i] == NULL)
			cout << "Destroyed\n";
		else if(provinces[i] == holdings.front())
			cout << "Empty\n";
		else
			provinces[i]->print();
		cout << endl;
	}

}

void Player::printArmy() const{

	cout << "Printing the Army:\n";
	if(army.empty())
		cout << "There is no army\n\n";
	else{
		for(int i = 0; i < army.size(); i++){
			if((army.at(i)->get_isDead() == false) && (army.at(i)->get_isTapped() == false)){
				cout << i << " : ";
				army.at(i)->print();
			}
			cout << endl;
		}
	}
}

void Player::printGameStatistics() const{

	cout << endl;
	cout << "Player \"" << playerName << "\" Statistics:\n";
	cout << "Items bought: " << itemsBought << endl;
	cout << "Followers bought: " << followersBought << endl;
	cout << "Personalities bought: " << personalitiesBought << endl;
	cout << "Holdings bought: " << holdingsBought << endl;
	cout << endl << endl;

}

void Player::printArena() const{

	printArmy();	

}

void Player::printHoldings() const{

	cout << "Printing the Holdings:";
	cout << endl;
	for(int i = 0; i < holdings.size(); i++){
		cout << i << ":";
		holdings.at(i)->print();
		cout << endl;
	}

}

void Player::untapArmy() const{

	for(int i = 0; i < army.size(); i++)
		army.at(i)->untap();

}

void Player::untapHoldings() const{

	for(int i = 0; i < holdings.size(); i++)
		holdings.at(i)->untap();

}

void Player::reset(){

	for(int i=0; i<attacking.size(); i++){
		army.push_back(attacking.at(i));
	}
	for(int i=0; i<defending.size(); i++){
		army.push_back(defending.at(i));
	}
	attacking.clear();
	defending.clear();
	attackPoints = 0;
	defendPoints = getInitDefense();

}

void Player::printPlayer() const{

	cout << "Player \"" << playerName;

	if(numberOfProvinces > 0)
		cout << "\", Provinces: " << numberOfProvinces << ", Defense: " << defendPoints << endl;
	else
		cout << "DEFEATED\n";

}

unsigned short Player::getHonour() const{

	return holdings.front()->get_honour();

}

unsigned short Player::getInitDefense() const{

	//holdings.front() == Stronghold
	return holdings.front()->get_initialDefense();

}

unsigned short Player::getMoney() const{

	return get_harvest(holdings);

}
