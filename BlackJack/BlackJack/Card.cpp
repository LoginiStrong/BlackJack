#include "Card.h"

//This class encapsulates all the qualities of a card contained in a standard deck

//the next three functions are accessors for the varialbes described in Card.h
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

//the next three functions are mutators for the varialbes described in Card.h
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
