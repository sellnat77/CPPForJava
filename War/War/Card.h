#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Card
{
private:
	int rank;
	string suit;
	string face;

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
	
	Card(int r, string s, string f)
	{
		rank = r;
		suit = s;
		face = f;
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

	string getFace()
	{
		return face;
	}

	void setValue(int r)
	{
		rank = r;
	}

	void setCard(int r)
	{
		rank = r;
	}

	void setCard(int r, string s)
	{
		rank = r;
		suit = s;
	}

	void setCard(int r, string s, string f)
	{
		rank = r;
		suit = s;
		face = f;
	}

	void displayCard()
	{
		if (getFace().empty())
		{
			cout << "\t" << getValue() << " of " << getSuit() << "\n";
		}
		else
		{
			cout << "\t" << getFace() << " of " << getSuit() << "\n";
		}
	}
};