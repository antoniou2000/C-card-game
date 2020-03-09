#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

enum  {PERSONALITY=0,HOLDING,FOLLOWER,ITEM};
enum  {MINE,GOLD_MINE,CRYSTAL_MINE};

class card{
protected:
	std::string name;
	unsigned int cost;
	bool isTapped;
public:
	card(std::string str,unsigned int temp ):name(str),cost(temp),isTapped(false){
		std::cout<<"A card has been created"<<std::endl;
	}
	~card(){
		std::cout<<"Card to be destroyed"<<std::endl;
	}
	std::string get_name(){
		return name;
	}
	unsigned int get_cost(){
		return cost;
	}
	bool get_isTapped(){
		return isTapped;
	}
	virtual void print(){

	}
	virtual int type(){
		return -1;
	}
	void tap(){
		isTapped=true;
	}
	void untap(){
		isTapped=false;
	}
};

class GreenCard:public card{
protected:
	unsigned int attackBonus;
	unsigned int defenseBonus;
	unsigned int minHonour;
	std::string cardText;
	unsigned int effectBonus;
	unsigned int effectCost;
public:
	GreenCard(std::string nam,unsigned int x1,unsigned int x2,unsigned int x3,unsigned int x4,unsigned int x5,unsigned int x6)
	:card(nam,x1),attackBonus(x2),defenseBonus(x3),minHonour(x4),effectBonus(x5),effectCost(x6)
	{
		std::cout<<"A green card has been created"<<std::endl;
	}
	~GreenCard(){
		std::cout<<"Green card to be destroyed"<<std::endl;
	}
	unsigned int get_attackBonus(){
		return attackBonus;
	}
	unsigned int get_defenseBonus(){
		return defenseBonus;
	}
	unsigned int get_minHonour(){
		return minHonour;
	}
	std::string get_cardText(){
		return cardText;
	}
	unsigned int get_effectBonus(){
		return effectBonus;
	}
	unsigned int get_effectCost(){
		return effectCost;
	}
	virtual void print(){
		//
	}
	virtual int type()=0;
	void detach(){
		delete this;
	}
	void effect(){
		attackBonus+=effectBonus;
		defenseBonus+=effectBonus;
	}
	virtual void sub_durability(int x){
		//
	}
};

class Follower:public GreenCard{
public:
	Follower(std::string nam,unsigned int x1,unsigned int x2,unsigned int x3,unsigned int x4,unsigned int x5,unsigned int x6)
	:GreenCard(nam,x1,x2,x3,x4,x5,x6){
		std::cout<<"A follower has been created"<<std::endl;
	}
	~Follower(){
		std::cout<<"Follower to be deleted"<<std::endl;
	}
	void print(){
		std::cout<<"-------------------------------"<<std::endl;
		std::cout<<"-"<<get_name()<<"-"<<std::endl;
		std::cout<<"Cost: "<<get_cost()<<std::endl;
		std::cout<<"Attack bonus: "<<get_attackBonus()<<std::endl;
		std::cout<<"Defense bonus: "<<get_defenseBonus()<<std::endl;
		std::cout<<"Minimum Honour: "<<get_minHonour()<<std::endl;
		std::cout<<"Text:"<<std::endl<<get_cardText()<<std::endl;
		std::cout<<"Effect bonus: "<<get_effectBonus()<<std::endl;
		std::cout<<"Effect cost: "<<get_effectCost()<<std::endl;
		std::cout<<"================================"<<std::endl;
	}
	int type(){
		return FOLLOWER;
	}
};


class Item:public GreenCard{
protected:
	unsigned int durability;
public:
	Item(std::string nam,unsigned int x1,unsigned int x2,unsigned int x3,unsigned int x4,unsigned int x5,unsigned int x6,unsigned int x7)
	:GreenCard(nam,x1,x2,x3,x4,x5,x6),durability(x7)
	{
		std::cout<<"An item has been created"<<std::endl;
	}
	~Item(){
		std::cout<<"Item to be deleted"<<std::endl;
	}
	unsigned int get_durability(){
		return durability;
	}
	void print(){
		std::cout<<"-------------------------------"<<std::endl;
		std::cout<<"-"<<get_name()<<"-"<<std::endl;
		std::cout<<"Cost: "<<get_cost()<<std::endl;
		std::cout<<"Attack bonus: "<<get_attackBonus()<<std::endl;
		std::cout<<"Defense bonus: "<<get_defenseBonus()<<std::endl;
		std::cout<<"Minimum Honour: "<<get_minHonour()<<std::endl;
		std::cout<<"Text:"<<std::endl<<get_cardText()<<std::endl;
		std::cout<<"Effect bonus: "<<get_effectBonus()<<std::endl;
		std::cout<<"Effect cost: "<<get_effectCost()<<std::endl;
		std::cout<<"Durability: "<<get_durability()<<std::endl;
		std::cout<<"================================"<<std::endl;
	}
	int type(){
		return ITEM;
	}
	void sub_durability(int x){
		durability-=x;
	}
};


class BlackCard:public card{
protected:
	bool isRevealed;
public:
	BlackCard(std::string s,unsigned int x):card(s,x),isRevealed(false){
		std::cout<<"A black card has been created"<<std::endl;
	}
	~BlackCard(){
		std::cout<<"Black card to be deleted"<<std::endl;
	}
	bool get_isRevealed(){
		return isRevealed;
	}
	void print(){

	}
	virtual int type()=0;
	void reveal(){
		isRevealed=true;
	}
	virtual unsigned int get_attack(){
		return 0;
	}
	virtual void kill_Card(){
		//
	}
	virtual bool get_isDead(){
		return true;
	}
	virtual unsigned int get_defense(){
		return 0;
	}
	virtual unsigned int get_honour(){
		return 0;
	}
	virtual unsigned int get_initialDefense(){
		return 0;
	}
	virtual bool isFull(unsigned int i){
		return true;
	}
	virtual unsigned int get_harvestValue(){
		return 0;
	}
	virtual bool equip(GreenCard* temp, unsigned int c){
		return false;
	}
	virtual void sub_honour(int x){
		//
	}
	virtual GreenCard * get_item0(){
		return NULL;
	}
	virtual GreenCard * get_item1(){
		return NULL;
	}
	virtual int has_upperHolding(){
		return 1;
	}
	virtual int has_subHolding(){
		return 1;
		}
	virtual void add_subHolding(BlackCard * temp){
		//
	}
	virtual void add_upperHolding(BlackCard * temp){
		//
	}
	 virtual void add_harvestValue(int x){
		//
	}
	virtual int mtype(){
		return -1;
	}
	virtual void add_to_subHolding(int x){
		//
	}
	virtual void add_to_upperHolding(int x){
		//
	}
	virtual BlackCard * get_subHolding(){
		return NULL;
	}
	virtual BlackCard * get_upperHolding(){
		return NULL;
	}
	virtual unsigned int get_initialValue(){
		return 1;
	}
	virtual bool fullChain(){
		return false;
	}
};

class personality:public BlackCard{
protected:
	unsigned int attack;
	unsigned int defense;
	unsigned int honour;
	bool isDead;
	GreenCard * follower[2];
 	GreenCard * item[2];
	unsigned int FinalAttack(){
		unsigned int temp=attack;
		if(follower[0])
			temp+=follower[0]->get_attackBonus();
		if(follower[1])
			temp+=follower[1]->get_attackBonus();
		if(item[0])
			temp+=item[0]->get_attackBonus();
		if(item[1])
			temp+=item[1]->get_attackBonus();
		return temp;
	}
public:
	personality(std::string s,unsigned int x1,unsigned int x2,unsigned int x3,unsigned int x4)
	:BlackCard(s,x1),attack(x2),defense(x3),honour(x4), isDead(false){
		follower[0]=NULL;
		follower[1]=NULL;
		item[0]=NULL;
		item[1]=NULL;
		std::cout<<"A personality has been created"<<std::endl;
	}
	~personality(){
		std::cout<<"Personality to be destroyed"<<std::endl;
	}
	unsigned int get_attack(){
		return attack;
	}
	unsigned int get_defense(){
		return defense;
	}
	unsigned int get_honour(){
		return honour;
	}
	bool get_isDead(){if(follower[0]!=NULL) follower[0]->print();
		return isDead;
	}
	GreenCard * get_item1(){
		return item[1];
	}
	GreenCard * get_item0(){
		return item[0];
	}
	GreenCard * get_follower0(){
		return follower[0];
	}
	GreenCard * get_follower1(){
		return follower[1];
	}
	void print(){
		if (get_isRevealed()){
		std::cout<<"-------------------------------"<<std::endl;
		std::cout<<"-"<<get_name()<<"-"<<std::endl;
		std::cout<<"Cost: "<<get_cost()<<std::endl;
		std::cout<<"Atttack: "<<get_attack()<<std::endl;
		std::cout<<"Defense: "<<get_defense()<<std::endl;
		std::cout<<"Honour: "<<get_honour()<<std::endl;
		std::cout<<"================================"<<std::endl;
		if(item[0]!=NULL) item[0]->print();
		if(item[1]!=NULL) item[1]->print();
		if(follower[0]!=NULL) follower[0]->print();
		if(follower[1]!=NULL) follower[1]->print();
	}
	else std::cout<<"CARD IS HIDDEN"<<std::endl<<"======================="<<std::endl;

}
	int type(){
		return PERSONALITY;
	}
bool isFull(unsigned int t){
	if(t==ITEM){
		if ((item[0]==NULL)||(item[1]==NULL))
		return false;
		else return true;
	}
	else{
		if((follower[0]==NULL)||(follower[1]==NULL))
			return false;
		else return true;
	}
	}
	void kill_Card(){
		isDead=true;
		if(!follower[0]){
			follower[0]->detach();
			if(!follower[1])
			follower[1]->detach();
		}
	}
	void change_isDead(){
		if(isDead)
			isDead=false;
			else isDead=true;
	}
	void sub_honour(int x){
		honour-=x;
	}
	bool equip(GreenCard * temp, unsigned int c){
		if(temp->type()==FOLLOWER){
			if(follower[0]==NULL){
				follower[0]=temp;
			}
				else follower[1]=temp;
		}
		else {
			if(item[0]==NULL)
				item[0]=temp;
				else item[1]=temp;
		}

		bool answer = false;
		if(c>=temp->get_effectCost()){
		std::cout<<"Do you want to activate the bonus effect "<<temp->get_effectBonus()<<" with cost "<<temp->get_effectCost()<<"(1=yes,0=no)?"<<std::endl;

		std::cin>>answer;
		if(answer){
			temp->effect();
		}
	}
		attack+=temp->get_attackBonus();
		defense+=temp->get_defenseBonus();
		return answer;
	}
};

class holding:public BlackCard{
protected:
	unsigned int harvestValue;
	const unsigned int initialValue;
public:
	holding(std::string s,unsigned int x1,unsigned int x2)
		:BlackCard(s,x1),harvestValue(x2),initialValue(x2)
		{
		std::cout<<"A holding has been created"<<std::endl;
	}
	~holding(){
		std::cout<<"Holding to be destroyed"<<std::endl;
	}
	unsigned int get_harvestValue(){
		return harvestValue;
	}
	void print(){
		if (get_isRevealed()){
		std::cout<<"-------------------------------"<<std::endl;
		std::cout<<"-"<<get_name()<<"-"<<std::endl;
		std::cout<<"Cost: "<<get_cost()<<std::endl;
		std::cout<<"Harvest value: "<<get_harvestValue()<<std::endl;
		std::cout<<"================================"<<std::endl;
	}
	else std::cout<<"CARD IS HIDDEN"<<std::endl<<"================="<<std::endl;
}
	int type(){
		return HOLDING;
	}
	void add_harvestValue(int x){
		harvestValue+=x;
	}
	unsigned int get_initialValue(){
		return initialValue;
	}
};

class stronghold:public holding{
protected:
	unsigned int honour;
	unsigned int initialDefense;
public:
	stronghold(std::string s)
	:holding(s,0,5),honour(5),initialDefense(5){
		std::cout<<"A stronghold has been created"<<std::endl;
	}
	~stronghold(){
		std::cout<<"Stronghold to be destroyed"<<std::endl;
	}
	unsigned int get_honour(){
		return honour;
	}
	unsigned int get_initialDefense(){
		return initialDefense;
	}
	void print(){
		std::cout<<"-------------------------------"<<std::endl;
		std::cout<<"-"<<get_name()<<"-"<<std::endl;
		std::cout<<"Cost: "<<get_cost()<<std::endl;
		std::cout<<"Harvest value: "<<get_harvestValue()<<std::endl;
		std::cout<<"Honour: "<<get_honour()<<std::endl;
		std::cout<<"Initial defense: "<<get_initialDefense()<<std::endl;
		std::cout<<"================================"<<std::endl;
	}
};

class footsoldier:public Follower{
public:
	footsoldier(std::string name):Follower(name,0,2,0,1,1,2){
		std::cout<<"A footsoldier has been created"<<std::endl;
	}
	~footsoldier(){
		std::cout<<"Footsoldier to be destroyed"<<std::endl;
	}
};

class archer:public Follower{
public:
	archer(std::string name):Follower(name,0,0,2,1,1,2){
		std::cout<<"An archer has been created"<<std::endl;
	}
	~archer(){
		std::cout<<"Archer to be destroyed"<<std::endl;
	}
};



class sieger:public Follower{
public:
	sieger(std::string name):Follower(name,5,3,3,2,2,3){
		std::cout<<"A sieger has been created"<<std::endl;
	}
	~sieger(){
		std::cout<<"Sieger to be destroyed"<<std::endl;
	}
};



class cavalry:public Follower{
public:
	cavalry(std::string name):Follower(name,3,4,2,3,3,4){
		std::cout<<"A cavalry has been created"<<std::endl;
	}
	~cavalry(){
		std::cout<<"Cavalry to be destroyed"<<std::endl;
	}
};


class naval:public Follower{
public:
	naval(std::string name):Follower(name,3,2,4,3,3,4){
		std::cout<<"A naval has been created"<<std::endl;
	}
	~naval(){
		std::cout<<"Naval to be destroyed"<<std::endl;
	}
};

class bushido:public Follower{
public:
	bushido(std::string name):Follower(name,8,8,8,6,3,8){
		std::cout<<"A bushido has been created"<<std::endl;
	}
	~bushido(){
		std::cout<<"Bushido to be destroyed"<<std::endl;
	}
};

class katana:public Item{
public:
	katana(std::string name):Item(name,0,2,0,1,1,2,3){
		std::cout<<"A katana has been created"<<std::endl;
	}
	~katana(){
		std::cout<<"Katana to be deleted"<<std::endl;
	}
};



class spear:public Item{
public:
	spear(std::string name):Item(name,0,0,2,1,1,2,3){
		std::cout<<"A spear has been created"<<std::endl;
	}
	~spear(){
		std::cout<<"Spear to be deleted"<<std::endl;
	}
};

class bow:public Item{
public:
	bow(std::string name):Item(name,2,2,2,2,3,4,5){
		std::cout<<"A bow has been created"<<std::endl;
	}
	~bow(){
		std::cout<<"Bow to be deleted"<<std::endl;
	}
};


class ninjato:public Item{
public:
	ninjato(std::string name):Item(name,4,3,3,3,2,2,4){
		std::cout<<"A ninjato has been created"<<std::endl;
	}
	~ninjato(){
		std::cout<<"Ninjato to be deleted"<<std::endl;
	}
};


class wakizashi:public Item{
public:
	wakizashi(std::string name):Item(name,8,5,5,3,3,3,8){
		std::cout<<"A wakizashi has been created"<<std::endl;
	}
	~wakizashi(){
		std::cout<<"Wakizashi to be deleted"<<std::endl;
	}
};


class attacker:public personality{
public:
	attacker(std::string name):personality(name,5,3,2,2){
		std::cout<<"An attacker has been created"<<std::endl;
	}
	~attacker(){
		std::cout<<"Attacker to be destroyed"<<std::endl;
	}
};


class defender:public personality{
public:
	defender(std::string name):personality(name,5,2,3,2){
		std::cout<<"A defender has been created"<<std::endl;
	}
	~defender(){
		std::cout<<"Defender to be destroyed"<<std::endl;
	}
};


class shogun:public personality{
public:
	shogun(std::string name):personality(name,15,10,5,10){
		std::cout<<"A shogun has been created"<<std::endl;
	}
	~shogun(){
		std::cout<<"Shogun to be destroyed"<<std::endl;
	}
};


class chancellor:public personality{
public:
	chancellor(std::string name):personality(name,15,5,10,8){
		std::cout<<"A chancellor has been created"<<std::endl;
	}
	~chancellor(){
		std::cout<<"Chancellor to be destroyed"<<std::endl;
	}
};

class champion:public personality{
public:
	champion(std::string name):personality(name,30,20,10,12){
		std::cout<<"A champion has been created"<<std::endl;
	}
	~champion(){
		std::cout<<"Champion to be destroyed"<<std::endl;
	}
};

class solo:public holding{
public:
	solo(std::string name):holding(name,2,2){
		std::cout<<"A solo has been created"<<std::endl;
	}
	~solo(){
		std::cout<<"Solo to be destroyed"<<std::endl;
	}
};


class plain:public holding{
public:
	plain(std::string name):holding(name,2,2){
		std::cout<<"A plain has been created"<<std::endl;
	}
	~plain(){
		std::cout<<"Plain to be destroyed"<<std::endl;
	}
};


class farms:public holding{
public:
	farms(std::string name):holding(name,3,4){
		std::cout<<"A farm has been created"<<std::endl;
	}
	~farms(){
		std::cout<<"Farms to be destroyed"<<std::endl;
	}
};


class mine:public holding{
private:
	BlackCard * upperHolding;
public:
	mine(std::string name):holding(name,5,3){
		upperHolding=NULL;
		std::cout<<"A mine has been created"<<std::endl;
	}
	~mine(){
		std::cout<<"Mine to be destroyed"<<std::endl;
	}
	void add_upperHolding(BlackCard*  temp){
		upperHolding=temp;
		if(temp!=NULL)
			temp->add_subHolding(this);
	}
	int has_upperHolding(){
		if(this->upperHolding==NULL)
			return 0;
		else
			return 1;
	}
	int mtype(){
		return MINE;
	}
	void add_to_upperHolding(int x){
		upperHolding->add_harvestValue(x);
	}
	BlackCard * get_upperHolding(){
		return upperHolding;
	}
};

class gold_mine:public holding{
private:
	BlackCard * upperHolding;
	BlackCard * subHolding;
public:
	gold_mine(std::string name):holding(name,7,5){
		upperHolding=NULL;
		subHolding=NULL;
		std::cout<<"A gold mine has been created"<<std::endl;
	}
	~gold_mine(){
		std::cout<<"Gold mine to be destroyed"<<std::endl;
	}
	void add_upperHolding(BlackCard* temp){
		upperHolding=temp;
		if(temp!=NULL)
			if (!temp->has_subHolding())
				temp->add_subHolding(this);
	}
	void add_subHolding(BlackCard * temp){
		subHolding=temp;
	}
	int has_upperHolding(){
		if(this->upperHolding==NULL)
			return 0;
		else
			return 1;
	}
	int has_subHolding(){
		if(this->subHolding==NULL)
			return 0;
		else
			return 1;
	}
	int mtype(){
		return GOLD_MINE;
	}
	void add_to_subHolding(int x){
		subHolding->add_harvestValue(x);
	}
	void add_to_upperHolding(int x){
		upperHolding->add_harvestValue(x);
	}
	BlackCard * get_subHolding(){
		return subHolding;
	}
	BlackCard * get_upperHolding(){
		return upperHolding;
	}
	bool fullChain(){
		if((has_subHolding())&&(has_upperHolding())){
			return true;
		}
		else return false;
	}
};

class crystal_mine:public holding{
private:
	BlackCard * subHolding;
public:
	crystal_mine(std::string name):holding(name,12,6){
		subHolding=NULL;
		std::cout<<"A crystal mine has been created"<<std::endl;
	}
	~crystal_mine(){
		std::cout<<"Crystal mine to be destroyed"<<std::endl;
	}
	void add_subHolding(BlackCard* temp){
		subHolding=temp;
		if(temp!=NULL)
			temp->add_upperHolding(this);
	}
	int has_subHolding(){
		if(this->subHolding==NULL)
			return 0;
		else
			return 1;
	}
	int mtype(){
		return CRYSTAL_MINE;
	}
	void add_to_subHolding(int x){
		subHolding->add_harvestValue(x);
	}
	BlackCard * get_subHolding(){
		return subHolding;
	}
};

void bla(std::vector <BlackCard *> ,unsigned int );
void make_chain(std::vector <BlackCard *>);
BlackCard * find_crystal_mine(std::vector <BlackCard *> ,int);
BlackCard * find_gold_mine(std::vector <BlackCard *> ,int );
BlackCard * find_mine(std::vector <BlackCard *>,int );
void subMoney(std::vector <BlackCard * > ,unsigned int );
unsigned int get_harvest(std::vector <BlackCard *> );
