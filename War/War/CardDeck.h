#include "Card.h"

class CardDeck
{
private:
	string* suits = new string[4] { "clubs", "hearts", "spades", "diamonds"};
	//string suits[4] = { { "clubs", "hearts", "spades", "diamonds" } };
	Card war[52];
public:

	CardDeck()
	{
		int j, k;
		//create deck of 52 cards
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 13; k++)
			{
				//war[0] = war(k, suits[j]);
				war[j + k].setCard(k, suits[j]);
					//=war(k, suits[j]);
			}
		}
	}

	void displayCardAt(int location)
	{
		war[location].displayCard();
		
	}

	int dealCard()
	{
		//return point value of card at top of deck
	}

	int cardsLeft()
	{
		//return the number of cards left
	}

	void shuffle()
	{
		//shuffle the deck
	}


};