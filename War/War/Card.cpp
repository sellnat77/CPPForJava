#include "Card.h"

Card::Card(){}

Card::Card(string s)
{
	suit = s;
}

Card::Card(int r, string s)
{
	rank = r;
	suit = s;
}

Card::Card(int r, string s, string f)
{
	rank = r;
	suit = s;
	face = f;
}

Card::Card(string face, string s)
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

int Card::getValue()
{
	return rank;
}

string Card::getSuit()
{
	return suit;
}

string Card::getFace()
{
	return face;
}

void Card::setValue(int r)
{
	rank = r;
}

void Card::setCard(int r)
{
	rank = r;
}

void Card::setCard(int r, string s)
{
	rank = r;
	suit = s;
}

void Card::setCard(int r, string s, string f)
{
	rank = r;
	suit = s;
	face = f;
}

void Card::displayCard()
{
	if (getFace().empty())
	{
		cout << "\t" << getValue() << " of " << getSuit() << "\n";
	}
	else
	{
		cout << "\t" << getFace () << " of " << getSuit() << "\n";
	}
}