

Authors:Kokolias Konstantinos-Marios,Stefanos Antoniou

Compile and run:make run

Code specifications:
-When asked to buy or destroy a card, enter the card's number(top left).

-In order to store our data we used mostly vectors from stl(for each player's deck and for the game board).

-Stronghold's stats are initialized with the numbers given from the card file, meaning that the player who goes first is always the one that his name is beibg entered first.

-If a player runs out of cards, a message indicates that no new cards are being inserted,aka the specific player's hand isn't refreshed and provinces are "empty".(Note: When a privince is
 destroyed, it points to NULL,whilst if it is empty(in case the cards run out) it points to the Stronghold).

-Harvest doesn't stack each round.

-When it comes to mine chains and their bonuses, a function named makechain does that operation:If the last holding bought is a type of mine then it searches for an adjacent and available
mine(mine <-> gold_mine<->crystal mine) using the find_(type of mine) functions.If a chains is formed, then each mine's harvest is changed acordingly.

-bla(...) function is called when the total defense of the attacked  is bigger or less than the attack he is receiving.(In the 1st case it is called for the attacker and in the 2nd 
it is called for the defender).As a result,personlities "die" until the specific number is matched and the ones that dont "die" have their items' durability reduced by 1.