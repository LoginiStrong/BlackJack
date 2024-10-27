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

private:
	vector<Card*> hand;
	int aceAmount;
};