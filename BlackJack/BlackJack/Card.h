#pragma once
#include <string>
#include <iostream>
using namespace std;

class Card
{
public:
	int getValue();
	string getFace();
	string getSuit();
	void setValue(int newVal);
	void setFace(string newFace);
	void setSuit(string newSuit);


private:
	int cardValue;//variable that holds the value of the card based on the rules of BlackJack
	string cardFace;//is the face of the card (such as Ace, 2, King, etc)
	string suit;//the suit of the cards
};
