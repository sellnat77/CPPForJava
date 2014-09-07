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
		if (allCards[k].getValue() != 0)
		{
			allCards[k].displayCard();
		}
	}
	cout << "\n";
}

/*void Deck::playWar()
{
	int k;
	int playAgain;
	bool playerOnesTurn = true;
	setPlayerOneScore(0);
	setPlayerTwoScore(0);

	cout << "\tDealing...prepare for WAR!\n";

	for (k = 0; k < 4; k++)
	{
		if (playerOnesTurn)
		{
			cout << "\nPlayer one draws...\t";
			incPlayerOne(dealCard());
			war[cardsDealt].setValue(0);
			cardsDealt++;
			system("pause");
			playerOnesTurn = false;
		}
		else
		{
			cout << "\nPlayer two draws...\t";
			incPlayerTwo(dealCard());
			war[cardsDealt].setValue(0);
			cardsDealt++;
			system("pause");
			playerOnesTurn = true;
		}
	}

	cout << "\t\tPlayer one: " << playerOneScore;
	cout << "\n\t\tPlayer two: " << playerTwoScore << "\n";

	if (getPlayerOneScore() > getPlayerTwoScore())
	{
		cout << "\n\t\t\tPLAYER ONE WINS!\n";
	}
	else if (getPlayerOneScore() == getPlayerTwoScore())
	{
		if (cardsDealt == 52)
		{
			cout << "Not enough cards! grabbing new shuffled deck...";
			CardDeck();
			cardsDealt = 0;
		}
		else
		{
			cout << "\n\t\t\tTIE! Play again!\n";
			playWar();
		}
	}
	else if (cardsDealt == 52)
	{
		cout << "Not enough cards! grabbing new deck...\n";
		CardDeck();
		cardsDealt = 0;
	}
	else
	{
		cout << "\n\t\t\tPLAYER TWO WINS!\n";
		if (cardsDealt == 52)
		{
			cout << "Not enough cards! grabbing new deck...\n";
			CardDeck();
			cardsDealt = 0;
		}
	}

	cout << "There are " << cardsLeft() << "cards left.\n";
	cout << "Want to play again? 1)yes 2)no ";

	cin >> playAgain;

	switch (playAgain)
	{
	case 1:
		playWar();
		break;

	default:
		break;
	}
}
*/