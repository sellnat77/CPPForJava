#include "Card.h"

class CardDeck
{
private:
	Card war[52];
	int playerOneScore = 0;
	int playerTwoScore=0;
	int cardsDealt = 0;
public:

	CardDeck()
	{
		string suits[4] = { "clubs", "hearts", "spades", "diamonds" };
		int j, k,count;
		count = 0;
		//create deck of 52 cards
		for (j = 0; j < 4; j++)
		{
			for (k = 1; k < 14; k++)
			{
				
				switch (k)
				{
				case 1:
					war[count].setCard(1, suits[j],"ace");
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

	void displayCardAt(int location)
	{
		war[location].displayCard();
		
	}

	int dealCard()
	{
		
		//return point vlaue on top of the deck
		displayCardAt(cardsDealt);
		
		if (cardsDealt == 48)
		{
			cout << "You have no more cards!...Grabbing a new deck\n";
			CardDeck();
			cardsDealt = 0;
		}
		return war[cardsDealt].getValue();
		war[cardsDealt].setCard(0);
		
	}

	int cardsLeft()
	{

		//return the number of cards left
		return sizeof(war)/sizeof(war[0]);
	}

	void shuffle()
	{
		//shuffle the deck
		random_shuffle(&war[0], &war[52]);

	}

	void showAllCards()
	{
		int k;
		for (k = 0; k < 52; k++)
		{
			if (war[k].getValue() != 0)
			{
				displayCardAt(k);
			}
		}
	}

	void playWar()
	{
		playerOneScore = 0;
		playerTwoScore = 0;
		cout << "Player one...\t";
		playerOneScore += dealCard();
		cardsDealt++;
		system("pause");
		cout << "\nPlayer two...\t";
		playerTwoScore += dealCard();
		cardsDealt++;
		system("pause");
		cout << "\nPlayer one...\t";
		playerOneScore += dealCard();
		cardsDealt++;
		system("pause");
		cout << "\nPlayer Two...\t";
		playerTwoScore += dealCard();
		cardsDealt++;
		system("pause");

		cout << "\t\t\t\tPlayer one: " << playerOneScore;
		cout << "\t Player two: " << playerTwoScore;

		if (playerOneScore > playerTwoScore)
		{
			cout << "PLAYER ONE WINS!\n";
		}
		else
		{
			cout << "\t\t\tPLAYER TWO WINS!\n";
		}
	}

	void mainMenu()
	{
		int decision;

		cout << "What would you like to do?\n\n";
		cout << "\t1) Get a new deck\n";
		cout << "\t2) Show the deck\n";
		cout << "\t3) Shuffle\n";
		cout << "\t4) Play WAR!\n";
		cout << "\t5) Exit\n";
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
			shuffle();
			mainMenu();
			break;
		case 4:
			playWar();
			mainMenu();
			break;
		default:
			cout << "Thanks for playing!";
			break;

		}
	}

};