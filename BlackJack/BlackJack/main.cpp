#include <iostream>
#include "Deck.h"
#include "Player.h"
#include <algorithm>
#include <random>
using namespace std;

/* This Program is a simple Black Jack game. It implements every Black Jack
rule excluding betting and splitting. The user gets to choose to hit or stand
during play and at the end of the game can choose to continue playing or end 
(all input is sanatized)
Author: Logan Strong
*/

int main()
{
	//this object and function are used to shuffle the deck (I used a referrence in the coding library
	random_device rd;
	mt19937 g(rd());

	Deck* casino = new Deck();
	casino->makeDeck();//even though its only called once, I made this function because I knew the main would already have a lot of code

	vector<Card*> deck;

	//below is the dealer object with a boolean that will represent if his turn is over or not and an int variable for the value og current cards held
	Player* dealer = new Player();
	bool dealerTurn;
	int dealerValue;

	//below is the player object with a boolean that will represent if his turn is over or not and an int variable for the value og current cards held
	Player* player = new Player();
	bool playerTurn;
	int playerValue;

	int choice;//integer that contains the user's choice to hit or stand

	bool gameActive = true;//boolean for if the game is in play or the user chose to end it

	while (gameActive)
	{
		//resets booleans  for both players
		playerTurn = true;
		dealerTurn = true;

		deck = casino->showDeck();//makes an instance of the casinos 52 card eck

		//shuffles deck multiple times
		for (int i = 0; i < 52; i++)
		{
			shuffle(deck.begin(), deck.end(), g);
		}

		//deals the first four cards in the deck (two to each player)
		for (int i = 0; i < 4; i++)
		{
			Card* temp = deck.back();
			deck.pop_back();

			if (i % 2 == 0)
			{
				dealer->addToHand(temp);
			}
			else
			{
				player->addToHand(temp);
			}
		}

		//This loop contians the players turn (will only end if the player stands or busts)
		while (playerTurn)
		{
			//resets ace count and value of current hand cause a new card is drawn
			playerValue = 0;
			player->clearAce();

			//displays the dealers first card and all the players cards as well as calculates their value
			for (int i = 0; i < player->getHand().size(); i++)
			{
				if (i == 0)
				{
					cout << "\nDealers Hand:\n";
					cout << dealer->getHand().at(0)->getFace() << dealer->getHand().at(0)->getSuit() << endl;
					cout << "\nPlayers Hand:\n";
				}

				cout << player->getHand().at(i)->getFace() << player->getHand().at(i)->getSuit() << endl;

				//I count the aces in order to calculate if I should make its value 1 or 11 later
				if (player->getHand().at(i)->getValue() == 11)
				{
					player->addAce();
				}
				playerValue += player->getHand().at(i)->getValue();
			}

			//checks if the players value exceeds 21 and subtracts ten accordingly based on how many aces
			for (int i = 0; i < player->amountOfAces(); i++)
			{
				if (playerValue > 21)
				{
					playerValue -= 10;
				}
			}

			cout << endl;

			//statements for if the player busts, gets a black jack or needs to make a choice
			if (playerValue > 21)
			{
				cout << "You Bust\n";
				playerTurn = false;
				dealerTurn = false;
			}
			else if (playerValue == 21)
			{
				cout << "Black Jack!!!\n";
				playerTurn = false;
			}
			else
			{
				cout << "Enter 1 to hit\nEnter 2 to stand\n";

				//boolean and loop are made for sanitizing user input
				bool valid = false;
				while (valid == false)
				{
					cin >> choice;
					if (choice == 1)//adds one card to the player's hand from the deck (Hit)
					{
						Card* temp = deck.back();
						deck.pop_back();
						player->addToHand(temp);
						valid = true;
					}
					else if (choice == 2)//player chooses to end their turn (Stand)
					{
						playerTurn = false;
						valid = true;
					}
					else
					{
						cout << "Please enter a valid input!\n";
					}
				}
			}
		}

		/*This loop automates the dealers turn
		The dealer will stand if they reach 17-21, until then they 
		will hit. If the dealer exceeds 21 they bust just like the player
		*/
		while (dealerTurn)
		{
			dealerValue = 0;
			cout << "Dealers Hand:\n";
			for (int i = 0; i < dealer->getHand().size(); i++)
			{
				cout << dealer->getHand().at(i)->getFace() << dealer->getHand().at(i)->getSuit() << endl;
				if (dealer->getHand().at(i)->getValue() == 11)
				{
					dealer->addAce();
				}
				dealerValue += dealer->getHand().at(i)->getValue();
			}
			for (int i = 0; i < dealer->amountOfAces(); i++)
			{
				if (dealerValue > 21)
				{
					dealerValue -= 10;
				}
			}
			cout << endl;
			for (int i = 0; i < player->getHand().size(); i++)
			{
				cout << player->getHand().at(i)->getFace() << player->getHand().at(i)->getSuit() << endl;
			}
			cout << endl;
			if (dealerValue > 21)
			{
				cout << "Dealer Busts, You Win!!!\n";
				dealerTurn = false;
			}
			else if (dealerValue == 17 || dealerValue == 18 || dealerValue == 19 || dealerValue == 20 || dealerValue == 21)
			{
				cout << "Dealer stands\n";
				if (dealerValue > playerValue)
				{
					cout << "Dealer Wins :(\n";
				}
				else if (dealerValue == playerValue)
				{
					cout << "Nobody Wins or Loses\n";
				}
				else if (playerValue <= 21)
				{
					cout << "You Win!!!\n";
				}
				dealerTurn = false;
			}
			else if (dealerValue > playerValue)
			{
				cout << "Dealer Wins :(\n";
				dealerTurn = false;
			}
			else
			{
				Card* temp = deck.back();
				deck.pop_back();
				dealer->addToHand(temp);
			}
		}
		cout << "Would you like to play again?\nEnter Y for yes or N for No\n";

		//sanitization loop for the player's choice to play another round or terminate the game
		bool valid = false;
		string choice;
		while (valid == false)
		{
			cin >> choice;
			if (choice == "Y" || choice == "y")
			{
				player->clearHand();
				dealer->clearHand();
				valid = true;
			}
			else if (choice == "N" || choice == "n")
			{
				exit(0);
			}
			else
			{
				cout << "Please enter Y for yes or N for No";
			}
		}
	}
}