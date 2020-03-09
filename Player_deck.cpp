#include "Player.h"

using namespace std;

void Player::DeckBuilder(){

	//Dynasty Deck
	
	//NO_ATTACKING 10
	for(int i = 0; i < 10; i++)
		dynastyDeck.push_back(new attacker("Steadfast bushi"));
	//NO_DEFENDING 10
	for(int i = 0; i < 10; i++)
		dynastyDeck.push_back(new defender("Footsoldiers"));

	//NO_SHOGUN 2
	dynastyDeck.push_back(new shogun("Akodo Kaneka"));
	dynastyDeck.push_back(new shogun("Isawa Shi en"));

	//NO_CHANCELLOR 2
	dynastyDeck.push_back(new chancellor("Hida Shozen"));
	dynastyDeck.push_back(new chancellor("Mirimuto Enishi"));

	//NO_CHAMPION 1
	dynastyDeck.push_back(new champion("Hida Kisada"));

	//NO_PLAIN 3
	for (int i = 0; i < 3; i++)
		dynastyDeck.push_back(new plain("Rice Fields"));
	//NO_FARMLANDS 3
	for (int i = 0; i < 3; i++)
		dynastyDeck.push_back(new farms("Fish Farms"));

	//NO_MINE 3
	for (int i = 0; i < 3; i++)
		dynastyDeck.push_back(new mine("Ashio Copper Mine"));
	//NO_GOLDMINE 3
	for (int i = 0; i < 3; i++)
		dynastyDeck.push_back(new gold_mine("Konomai Gold Mine"));
	//NO_CRYSTALMINE 3
	for (int i = 0; i < 3; i++)
		dynastyDeck.push_back(new crystal_mine("Ichinokawa Crystal Mine"));
	//NO GIFTSANDFAVOUR 2
	for (int i = 0; i < 2; i++)
		dynastyDeck.push_back(new solo("Gifts and Favors"));

	//Fate Deck

	//NO_FOOTSOLDIER = 6
	for (int i = 0; i < 6; i++)
		fateDeck.push_back(new footsoldier("Peasants"));
	//NO_ARCHER = 6
	for (int i = 0; i < 6; i++)
		fateDeck.push_back(new archer("Elite Troops"));
	//NO_SIEGER = 4
	for (int i = 0; i < 4; i++)
		fateDeck.push_back(new sieger("Immortal Bushi"));
	//NO_CAVALRY = 5
	for (int i = 0; i < 5; i++)
		fateDeck.push_back(new cavalry("Unicorn Horses"));
	//NO_NAVAL = 5
	for (int i = 0; i < 5; i++)
		fateDeck.push_back(new naval("Yomi Ships"));
	//NO_BUSHIDO = 2
	for (int i = 0; i < 2; i++)
		fateDeck.push_back(new bushido("7 Samurai"));

	//NO_KATANA = 4
	for (int i = 0; i < 4; i++)
		fateDeck.push_back(new katana("Daijtso"));
	//NO_BOW = 3
	for (int i = 0; i < 3; i++)
		fateDeck.push_back(new bow("Yumi"));
	//NO_SPEAR = 2
	for (int i = 0; i < 2; i++)
		fateDeck.push_back(new spear("Kama"));
	//NO_NINJATO = 2
	for (int i = 0; i < 2; i++)
		fateDeck.push_back(new ninjato("Butterfly Dagger"));
	//NO_FOOTSOLDIER = 1
	fateDeck.push_back(new wakizashi("Kusanagi"));


	DeckShuffle();

	for(int i = 0; i < 4; i++){
		provinces[i] = dynastyDeck.back();
		dynastyDeck.pop_back();
	}

	for(int i = 0; i < 6; i++){
		hand.push_back(fateDeck.back());
		fateDeck.pop_back();
	}


	holdings.push_back(new stronghold("Stronghold"));
	defendPoints = getInitDefense();

}

void Player::DeckShuffle(){

	for(int i=0; i < 100; i++){

		int pos1 = rand()%(dynastyDeck.size());
		int pos2 = rand()%(dynastyDeck.size());

		BlackCard* temp = dynastyDeck.at(pos1);
		dynastyDeck.at(pos1) = dynastyDeck.at(pos2);
		dynastyDeck.at(pos2) = temp;

	}


	for(int i=0; i < 100; i++){

		int pos1 = rand()%(fateDeck.size());
		int pos2 = rand()%(fateDeck.size());

		GreenCard* temp = fateDeck.at(pos1);
		fateDeck.at(pos1) = fateDeck.at(pos2);
		fateDeck.at(pos2) = temp;

	}

}
