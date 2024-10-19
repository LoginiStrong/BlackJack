#include "Card.h"

int Card::getValue()
{
	return cardValue;
}

string Card::getFace()
{
	return cardFace;
}

void Card::setValue(int newVal)
{
	cardValue = newVal;
}

void Card::setFace(string newFace)
{
	cardFace = newFace;
}