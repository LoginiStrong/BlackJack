#include <iostream>
#include "Card.h"
using namespace std;

int main()
{

	cout << "hi\n";
	Card* temp = new Card();
	temp->setFace("testing");
	cout << temp->getFace();
}