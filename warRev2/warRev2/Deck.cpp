#include "Deck.h"

Deck::Deck()
{	
	char suits[4] = { 'c', 'h', 's', 'd' };
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
	if (cardsDealt == 52)
	{
		cout << "\nNot enough cards, initializing a new deck.";
		Deck();
	}
	else
	{
		allCards[cardsDealt].displayCard();
	}
	return allCards[cardsDealt++];
}

int Deck::cardsLeft()
{
	int k, cards;
	cards = 0;

	for (k = 0; k < 52; k++)
	{
		if (allCards[k].getRank() != '0')
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

		temp = allCards[k];
		allCards[k] = allCards[randLoc];
		allCards[randLoc] = temp;
	}
}

void Deck::showAllCards()
{
	int k;
	cout << "\n";
	for (k = 0; k < 52; k++)
	{
		if (allCards[k].getRank() != '0')
		{
			allCards[k].displayCard();
		}
	}
	cout << "\n";
}