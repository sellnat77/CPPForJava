#include "Deck.h"
#include <string>
Deck::Deck()
{	
	char suits[4] = { 05, 03, 06, 04 };
	int j, k, pos;
	cardsDealt = 0;
	pos = 0;

	//create deck of 52 cards
	for (j = 0; j < 4; j++)
	{
		for (k = 1; k < 14; k++)
		{
			allCards[pos] = Card(k, suits[j]);
			pos++;
		}
	}
}

Card Deck::deal()
{
	Card temp;
	int topOfDeck = 0;
	while (allCards[topOfDeck].getValue() == 0)
	{
		if (topOfDeck > 52)
		{
			topOfDeck = 0;
		}
		topOfDeck++;
	}
	temp = allCards[topOfDeck];
	temp.displayCard();
	allCards[topOfDeck].setRank(0);
	return temp;	
}

int Deck::cardsLeft()
{
	int k, cards;
	cards = 0;

	for (k = 0; k < 52; k++)
	{
		if (allCards[k].getRank() != 0)
		{
			cards++;
		}
	}
	return cards;
}

void Deck::shuffle()
{
	//shuffle the deck
	int k, randLoc;
	Card temp;

	for (k = 0; k < 52; k++)
	{
		randLoc = rand() % 52;

		temp              = allCards[k];
		allCards[k]       = allCards[randLoc];
		allCards[randLoc] = temp;
	}
}

void Deck::showAllCards()
{
	int k;
	cout << "\n";
	for (k = 0; k < 52; k++)
	{
		if (allCards[k].getValue() != 0)
		{
			if (k % 13 == 0 && k != 0)
			{
				cout << "\n";
			}
			allCards[k].displayCard();			
		}
	}
	cout << "\n";
}

void Deck::centerText(string text)
{
	int k,length;

	length = (80-text.length())/2;

	for (k = 0; k < length; k++)
	{
		cout << " ";
	}
	cout << text << endl;
}