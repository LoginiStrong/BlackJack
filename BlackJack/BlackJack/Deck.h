#pragma once
#include "Card.h"
#include <string>
#include <vector>
using namespace std;

class Deck {
public:
	void makeDeck();
	vector<Card*> showDeck();

private:
	vector<Card*> tablesDeck;//vector that holds all 52 standard cards
};
