#include "Deck.h"

//Class and object that encapsulates all 52 unique crad objects (the constructor is the main reason for this class)

//this function returns the vector of cards in the deck
vector<Card*> Deck::showDeck()
{
	return tablesDeck;
}

//this function uses a looped switch case statement to construct all 52 standard cards in a deck
void Deck::makeDeck()
{
	string suit = " of Hearts";
	//loop for the 4 kinds of suits
	for (int i = 0; i < 4; i++)
	{
		if (i == 1)
		{
			suit = " of Clubs";
		}
		else if (i == 2)
		{
			suit = " of Spades";
		}
		else if (i == 3)
		{
			suit = " of Diamonds";
		}
		//loop for the 13 kinds of cards
		for (int j = 1; j < 14; j++)
		{
			Card* temp = new Card();
			switch (j)
			{
			case 1:
				temp->setFace("Ace");
				temp->setValue(11);
				temp->setSuit(suit);
				break;
			case 2:
				temp->setFace("2");
				temp->setValue(2);
				temp->setSuit(suit);
				break;
			case 3:
				temp->setFace("3");
				temp->setValue(3);
				temp->setSuit(suit);
				break;
			case 4:
				temp->setFace("4");
				temp->setValue(4);
				temp->setSuit(suit);
				break;
			case 5:
				temp->setFace("5");
				temp->setValue(5);
				temp->setSuit(suit);
				break;
			case 6:
				temp->setFace("6");
				temp->setValue(6);
				temp->setSuit(suit);
				break;
			case 7:
				temp->setFace("7");
				temp->setValue(7);
				temp->setSuit(suit);
				break;
			case 8:
				temp->setFace("8");
				temp->setValue(8);
				temp->setSuit(suit);
				break;
			case 9:
				temp->setFace("9");
				temp->setValue(9);
				temp->setSuit(suit);
				break;
			case 10:
				temp->setFace("10");
				temp->setValue(10);
				temp->setSuit(suit);
				break;
			case 11:
				temp->setFace("Jack");
				temp->setValue(10);
				temp->setSuit(suit);
				break;
			case 12:
				temp->setFace("Queen");
				temp->setValue(10);
				temp->setSuit(suit);
				break;
			case 13:
				temp->setFace("King");
				temp->setValue(10);
				temp->setSuit(suit);
				break;


			}
			tablesDeck.push_back(temp);
		}
	}
}