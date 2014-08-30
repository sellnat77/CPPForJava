#include <iostream>
#include <string>

using namespace std;
class Card
{
private:
	int rank;
	string suit;


public:
	Card(){}

	Card(string s)
	{
		suit = s;
	}

	Card(int r, string s)
	{
		rank = r;
		suit = s;
	}

	Card(string face, string s)
	{
		if (face == "ace")
		{
			rank = 1;
		}
		else
		{
			rank = 10;
		}
		suit = s;
	}

	int getValue()
	{
		return rank;
	}

	string getSuit()
	{
		return suit;
	}

	void setCard(int r, string s)
	{
		rank = r;
		suit = s;
	}

	void setCard(string face, string s)
	{
		if (face == "ace")
		{
			rank = 1;
		}
		else
		{
			rank = 10;
		}
		suit = s;
	}

	void displayCard()
	{
		cout << "\t" << this->getValue() << " of " << this->getSuit() << "\n";
	}





};