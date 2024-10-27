#include "Card.h"

int Card::getValue()
{
	return cardValue;
}

string Card::getFace()
{
	return cardFace;
}

string Card::getSuit()
{
	return suit;
}

void Card::setValue(int newVal)
{
	cardValue = newVal;
}

void Card::setFace(string newFace)
{
	cardFace = newFace;
}

void Card::setSuit(string newSuit)
{
	suit = newSuit;
}
