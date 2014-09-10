#include "Card.h""

/**
 * Default constructor sets rank and suit to '0'
 */
Card::Card()
{
	rank = '0';
	suit = '0';
}

/**
 * Full constructor assigns appropriate rank and suit
 */
Card::Card(char r, char s)
{
	rank = r;
	suit = s;
}

/**
 * Rank mutator
 */
void Card::setRank(char r)
{
	rank = r;
}

/**
 * Suit mutator
 */
void Card::setSuit(char s)
{
	suit = s;
}

/**
 * Rank Accessor
 */
char Card::getRank()
{
	return rank;
}

/**
 * Suit accessor
 */
char Card::getSuit()
{
	return suit;
}

/**
 * Returns the (int) value of any card object
 * Value is 10 if face card
 */
int Card::getValue()
{
	int value;

	value = (int)(getRank());

	if (value > 10)
	{
		value = 10;
	}
	return value;
}

/**
 * Displays card with appropriate rank and suit
 * based on its associated private members
 */
void Card::displayCard()
{
	int value;
	value = rank;
	switch (value)
	{
	case  1:
		cout << "Ace of " << suit << "\n";
		break;
	case 11:
		cout << "Jack of " << suit << "\n";
		break;
	case 12:
		cout << "Queen of " << suit << "\n";
		break;
	case 13:
		cout << "King of " << suit << "\n";
		break;
	default:
		cout << value << " of " << suit << "\n";
		break;
	}
}