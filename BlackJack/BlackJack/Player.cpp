#include "Player.h"

vector<Card*> Player::getHand()
{
	return hand;
}

void Player::addToHand(Card* newHand)
{
	hand.push_back(newHand);
}

int Player::amountOfAces()
{
	return aceAmount;
}

void Player::addAce()
{
	aceAmount++;
}

void Player::clearHand()
{
	hand.clear();
}