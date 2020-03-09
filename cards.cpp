#include "cards.h"
#include <vector>

using namespace std;

unsigned int get_harvest(vector <BlackCard *> temp){
	unsigned int x=0;
	for(int i=0; i < temp.size(); i++){
		if (temp.at(i)->get_isTapped()==false)
   		x+=temp.at(i)->get_harvestValue();
}
return x;
}

void subMoney(vector <BlackCard * > temp,unsigned int x){
	unsigned int i=0;
	while((x>0)&&(i<temp.size())){
		temp.at(i)->tap();
		x-=temp.at(i)->get_harvestValue();
		i++;
	}
}

BlackCard * find_mine(vector <BlackCard *> temp,int x){
	for(;x>0;x--){
		if((temp.at(x)->mtype()==MINE)&&(!(temp.at(x)->has_upperHolding()))){
			return temp.at(x);
		}
	}
		return NULL;
	}


BlackCard * find_gold_mine(vector <BlackCard *> temp,int x){
	if(temp.at(x)->mtype()==MINE){
	for(;x>0;x--){
		if((temp.at(x)->mtype()==GOLD_MINE)&&(!(temp.at(x)->has_subHolding()))){
			return temp.at(x);
		}
		}
	}
	else{
	for(;x>0;x--){
		if((temp.at(x)->mtype()==GOLD_MINE)&&(!(temp.at(x)->has_upperHolding()))){
			return temp.at(x);
		}
		}
	}
	return NULL;
}

BlackCard * find_crystal_mine(vector <BlackCard *> temp,int x){
	for(;x>0;x--){
		if(temp.at(x)->mtype()==CRYSTAL_MINE){
			if(!(temp.at(x)->has_subHolding()))
			return temp.at(x);
		}
	}
		return NULL;
	}


	void make_chain(vector <BlackCard *> temp){
			int i=temp.size()-1;
			if(temp.at(i)->mtype()==MINE){
				temp.at(i)->add_upperHolding(find_gold_mine(temp,i));
				if(temp.at(i)->has_upperHolding()){
					temp.at(i)->add_harvestValue(2);
					BlackCard * gold=temp.at(i)->get_upperHolding();
					gold->add_harvestValue(4);
					if(gold->fullChain()){
						gold->add_harvestValue(2*gold->get_initialValue());
						BlackCard * crystal=gold->get_upperHolding();
						crystal->add_harvestValue(3*crystal->get_initialValue());
					}
				}
			}
			else if(temp.at(i)->mtype()==CRYSTAL_MINE){
				temp.at(i)->add_subHolding(find_gold_mine(temp,i));
				if(temp.at(i)->has_subHolding()){
					temp.at(i)->add_harvestValue(temp.at(i)->get_initialValue());
					BlackCard * gold=temp.at(i)->get_subHolding();
					gold->add_harvestValue(5);
					if(gold->fullChain()){
						gold->add_harvestValue(2*gold->get_initialValue());
						temp.at(i)->add_harvestValue(3*temp.at(i)->get_initialValue());
					}
				}
			}
			else if(temp.at(i)->mtype()==GOLD_MINE){
				temp.at(i)->add_upperHolding(find_crystal_mine(temp,i));
				if(temp.at(i)->has_upperHolding()){
					temp.at(i)->add_harvestValue(5);
					BlackCard * crystal=temp.at(i)->get_upperHolding();
					crystal->add_harvestValue(crystal->get_initialValue());
				}
				temp.at(i)->add_subHolding(find_mine(temp,i));
				if(temp.at(i)->has_subHolding()){
					temp.at(i)->add_harvestValue(4);
					temp.at(i)->add_to_subHolding(2);
				}
				if(temp.at(i)->fullChain()){
					temp.at(i)->add_harvestValue(2*temp.at(i)->get_initialValue());
					BlackCard * crystal=temp.at(i)->get_upperHolding();
					crystal->add_harvestValue(3*crystal->get_initialValue());
				}
		 }

	}

void bla(vector <BlackCard *> temp,unsigned int i){
	for(int x=0;x<temp.size();x++){
		i-=temp.at(x)->get_attack();
		if(i>=0){
			temp.at(x)->kill_Card();
		}
		else{
			temp.at(x)->sub_honour(1);
			GreenCard * i0;
			GreenCard * i1;
			i0=temp.at(x)->get_item0();
			i1=temp.at(x)->get_item1();
			if(i1&&i0){
				i1->sub_durability(1);
				i0->sub_durability(1);
			}
			else if (i0)
			i0->sub_durability(1);
		}
	}
}
