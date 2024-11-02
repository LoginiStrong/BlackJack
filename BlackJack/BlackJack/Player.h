#pragma once
#include "Card.h"
#include <string>
#include <vector>
using namespace std;

class Player {

public:
	vector<Card*> getHand();
	void addToHand(Card* newCard);
	int amountOfAces();
	void addAce();
	void clearHand();
	void clearAce();

private:
	vector<Card*> hand;//players current hand
	int aceAmount;//amount of aces the player has
};