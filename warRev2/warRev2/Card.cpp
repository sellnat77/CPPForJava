#include "Card.h""

Card::Card()
{
	rank = '0';
	suit = '0';
}

Card::Card(char r, char s)
{
	rank = r;
	suit = s;
}

void Card::setRank(char r)
{
	rank = r;
}

void Card::setSuit(char s)
{
	suit = s;
}

char Card::getRank()
{
	return rank;
}

char Card::getSuit()
{
	return suit;
}

void Card::displayCard()
{
	switch ((int)(rank))
	{
	case  1:
		cout << "\tAce of " << suit << "\n";
		break;
	case 11:
		cout << "\tJack of " << suit << "\n";
		break;
	case 12:
		cout << "\tQueen of " << suit << "\n";
		break;
	case 13:
		cout << "\tKing of " << suit << "\n";
		break;
	default:
		cout << "\t" << (int)(rank) << " of " << suit << "\n";
		break;
	}
}