#include "CardDeck.h"
#include <array>

CardDeck::CardDeck()
{
	
	string suits[4] = { "clubs", "hearts", "spades", "diamonds" };
	int j, k, count;
	count = 0;

	//create deck of 52 cards
	for (j = 0; j < 4; j++)
	{
		for (k = 1; k < 14; k++)
		{

			switch (k)
			{
			case 1:
				
				war[count].setCard(1, suits[j], "ace");
				displayCardAt(count);
				break;
			case 11:
				
				war[count].setCard(10, suits[j], "king");
				displayCardAt(count);
				break;
			case 12:
				
				war[count].setCard(10, suits[j], "queen");
				displayCardAt(count);
				break;
			case 13:
				
				war[count].setCard(10, suits[j], "jack");
				displayCardAt(count);
				break;
			default:
				
				war[count].setCard(k, suits[j]);
				displayCardAt(count);
				break;
			}
			count++;
		}
	}
	
}

void CardDeck::newDeck()
{
	string suits[4] = { "clubs", "hearts", "spades", "diamonds" };
	int j, k,m,count;
	count = 0;
	cardsDealt = 0;

	//create deck of 52 cards
	for (j = 0; j < 4; j++)
	{
		for (k = 1; k < 14; k++)
		{

			switch (k)
			{
			case 1:

				war[count].setCard(1, suits[j], "ace");
				displayCardAt(count);
				break;
			case 11:

				war[count].setCard(10, suits[j], "king");
				displayCardAt(count);
				break;
			case 12:

				war[count].setCard(10, suits[j], "queen");
				displayCardAt(count);
				break;
			case 13:

				war[count].setCard(10, suits[j], "jack");
				displayCardAt(count);
				break;
			default:

				war[count].setCard(k, suits[j]);
				displayCardAt(count);
				break;
			}
			count++;
		}
	}
}

void CardDeck::displayCardAt(int location)
{
	war[location].displayCard();
}

int CardDeck::dealCard()
{
	//return point vlaue on top of the deck
	

	if (cardsDealt == 52)
	{
		cout << "You have no more cards!...Grabbing a new deck\n";
		CardDeck();
		cardsDealt = 0;
	}
	while (war[cardsDealt].getValue() == 0)
	{
		cardsDealt++;
	}
	displayCardAt(cardsDealt);
	
	return war[cardsDealt].getValue();	
}


int CardDeck::cardsLeft()
{
	int k,cards;
	cards = 0;

	for (k = 0; k < 52; k++)
	{
		if (war[k].getValue() != 0)
		{
			cards++;
		}

	}


	return cards;
}
int CardDeck::getCardsDealt()
{
	return cardsDealt;
}
int CardDeck::getPlayerOneScore()
{
	return playerOneScore;
}
int CardDeck::getPlayerTwoScore()
{
	return playerTwoScore;
}

void CardDeck::setPlayerOneScore(int s)
{
	playerOneScore = s;
}
void CardDeck::setPlayerTwoScore(int s)
{
	playerTwoScore = s;
}

void CardDeck::incPlayerOne(int s)
{
	playerOneScore += s;
}
void CardDeck::incPlayerTwo(int s)
{
	playerTwoScore += s;
}
void CardDeck::setCardsDealt(int c)
{
	cardsDealt = c;
}
void CardDeck::incCardsDealt(int c)
{
	cardsDealt += c;
}
void CardDeck::shuffle()
{
	//shuffle the deck
	int k, randLoc;
	Card temp;

	cardsDealt = 0;

	for (k = 0; k < 52; k++)
	{
		randLoc = rand() % 52;

		temp = war[k];
		war[k] = war[randLoc];
		war[randLoc] = temp;
	}
}
void CardDeck::showAllCards()
{
	int k;
	cout << "\n";
	for (k = 0; k < 52; k++)
	{
		if (war[k].getValue() != 0)
		{
			displayCardAt(k);
		}
	}
	cout << "\n";
}


void CardDeck::playWar()
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

void CardDeck::checkScore()
{
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
		cout << "Not enough cards! grabbing new shuffled deck...\n";
		CardDeck();
		cardsDealt = 0;
	}
	else
	{
		cout << "\n\t\t\tPLAYER TWO WINS!\n";
	}
}


void CardDeck::mainMenu()
{
	int decision;

	cout << "What would you like to do?\n\n";
	cout << "\t1) Get a new deck\n";
	cout << "\t2) Show the deck\n";
	cout << "\t3) How many cards are left?\n";
	cout << "\t4) Shuffle\n";
	cout << "\t5) Play WAR!\n";
	cout << "\t6) Exit\n";
	
	cin >> decision;
	switch (decision)
	{
	case 1:
		CardDeck();
		cardsDealt = 0;
		mainMenu();
		break;

	case 2:
		showAllCards();
		mainMenu();
		break;

	case 3:
		cout << "There are " << cardsLeft() << " cards left.\n";
		mainMenu();
		break;

	case 4:
		shuffle();
		mainMenu();
		break;

	case 5:
		playWar();
		mainMenu();
		break;

	default:
		cout << "Thanks for playing!\n";
		break;
	}
}
