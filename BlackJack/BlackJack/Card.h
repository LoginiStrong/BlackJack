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
	int cardValue;
	string cardFace;
	string suit;
};
