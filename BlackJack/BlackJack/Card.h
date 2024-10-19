#pragma once
#include <string>
using namespace std;

class Card
{
public:
	int getValue();
	string getFace();
	void setValue(int newVal);
	void setFace(string newFace);

private:
	int cardValue;
	string cardFace;
};