#include "Card.h"

class CardDeck
{
private:
	//string suits = new string[4] { "clubs", "hearts", "spades", "diamonds"};
	//static const string suits[4] = { "clubs", "hearts", "spades", "diamonds" };
	Card war[52];
public:

	CardDeck()
	{
		string suits[4] = { "clubs", "hearts", "spades", "diamonds" };
		int j, k;
		//create deck of 52 cards
		for (j = 0; j < 4; j++)
		{
			for (k = 1; k < 14; k++)
			{
				switch (k)
				{
				case 1:
					war[j + k].setCard(1, suits[j],"ace");
					displayCardAt(k);
					break;
				case 11:
					war[j + k].setCard(10, suits[j],"king");
					displayCardAt(k);
					break;
				case 12:
					war[j + k].setCard(10, suits[j], "queen");
					displayCardAt(k);
					break;
				case 13:
					war[j + k].setCard(10, suits[j], "jack");
					displayCardAt(k);
					break;
				default:
					war[j + k].setCard(k, suits[j]);
					displayCardAt(k);
					break;
				}
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