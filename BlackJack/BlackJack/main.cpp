#include <iostream>
#include "Deck.h"
#include "Player.h"
#include <algorithm>
#include <random>
using namespace std;

int main()
{

	cout << "hi\n";

	random_device rd;
	mt19937 g(rd());

	Deck* casino = new Deck();
	casino->makeDeck();

	vector<Card*> deck;


	Player* dealer = new Player();
	bool dealerTurn;
	int dealerValue;
	Player* player = new Player();
	bool playerTurn;
	bool playerWin;
	int playerValue = 0;
	int choice;

	bool gameActive = true;

	while (gameActive)
	{
		playerTurn = true;
		dealerTurn = true;
		playerWin = true;
		deck = casino->showDeck();

		for (int i = 0; i < 52; i++)
		{
			shuffle(deck.begin(), deck.end(), g);
		}

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

		while (playerTurn)
		{
			playerValue = 0;
			for (int i = 0; i < player->getHand().size(); i++)
			{
				if (i == 0)
				{
					cout << "Dealers Hand:\n";
					cout << dealer->getHand().at(0)->getFace() << dealer->getHand().at(0)->getSuit() << endl;
					cout << "\nPlayers Hand:\n";
				}

				cout << player->getHand().at(i)->getFace() << player->getHand().at(i)->getSuit() << endl;
				if (player->getHand().at(i)->getValue() == 11)
				{
					player->addAce();
				}
				playerValue += player->getHand().at(i)->getValue();
			}
			for (int i = 0; i < player->amountOfAces(); i++)
			{
				if (playerValue > 21)
				{
					playerValue -= 10;
				}
			}


			cout << endl;
			if (playerValue > 21)
			{
				cout << "You Bust\n";
				playerTurn = false;
				dealerTurn = false;
			}
			else if (playerValue == 21)
			{
				cout << "Black Jack!!! You Win!!!\n";
				playerTurn = false;
			}
			else
			{
				cout << "Enter 1 to hit\nEnter 2 to stand\n";

				bool valid = false;
				while (valid == false)
				{
					cin >> choice;
					if (choice == 1)
					{
						Card* temp = deck.back();
						deck.pop_back();
						player->addToHand(temp);
						valid = true;
					}
					else if (choice == 2)
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
				playerWin = false;
			}
			else
			{
				Card* temp = deck.back();
				deck.pop_back();
				dealer->addToHand(temp);
			}
		}
		cout << "Would you like to play again?\n Enter Y for yes or N for No\n";
		bool valid = false;
		string choice;
		while (valid == false)
		{
			cin >> choice;
			if (choice == "Y")
			{
				player->clearHand();
				dealer->clearHand();
				valid = true;
			}
			else if (choice == "N")
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