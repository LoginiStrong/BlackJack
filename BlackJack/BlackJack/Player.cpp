#include "Player.h"

//This class acts as a player entity who can possess cards that will be dealt from the deck

//returns players current hand
vector<Card*> Player::getHand()
{
	return hand;
}

//adds a card to the players hand
void Player::addToHand(Card* newHand)
{
	hand.push_back(newHand);
}

//returns the amount of aces the player has
int Player::amountOfAces()
{
	return aceAmount;
}

//adds one ace to the players hand
void Player::addAce()
{
	aceAmount++;
}

//clears the players hand in the event of restarting the game
void Player::clearHand()
{
	hand.clear();
}

void Player::clearAce()
{
	aceAmount = 0;
}