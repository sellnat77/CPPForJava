#include "Card.h"

class CardDeck
{

private:
	Card war[52];
	int playerOneScore = 0;
	int playerTwoScore = 0;
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
		
		if (cardsDealt == 52)
		{
			cout << "You have no more cards!...Grabbing a new deck\n";
			CardDeck();
			cardsDealt = 0;
		}
		return war[cardsDealt].getValue();
		
		war[cardsDealt].setValue(0);		
	}

	int cardsLeft()
	{
		return 52-cardsDealt;
	}

	void shuffle()
	{
		//shuffle the deck
		int k,randLoc;
		Card temp;

		for (k = 0; k < 52; k++)
		{
			randLoc = rand() % 52;

			temp         = war[k]; 
			war[k]       = war[randLoc]; 
			war[randLoc] = temp;
		}		
	}

	void showAllCards()
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

	void playWar()
	{
		int k;
		int playAgain;
		bool playerOnesTurn = true;
		playerOneScore = 0;
		playerTwoScore = 0;

		cout << "\tDealing...prepare for WAR!\n";

		for (k = 0; k < 4; k++)
		{
			if (playerOnesTurn)
			{
				cout << "\nPlayer one draws...\t";
				playerOneScore += dealCard();
				cardsDealt++;
				system("pause");
				playerOnesTurn = false;
			}
			else
			{
				cout << "\nPlayer two draws...\t";
				playerTwoScore += dealCard();
				cardsDealt++;
				system("pause");
				playerOnesTurn = true;
			}
		}

		cout << "\t\tPlayer one: " << playerOneScore;
		cout << "\n\t\tPlayer two: " << playerTwoScore << "\n";

		if (playerOneScore > playerTwoScore)
		{
			cout << "\n\t\t\tPLAYER ONE WINS!\n";
		}
		else if (playerOneScore == playerTwoScore)
		{
			if (cardsDealt == 52)
			{
				cout << "Not enough cards! grabbing new shuffled deck...";
				CardDeck();
				//shuffle();
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
			//shuffle();
			cardsDealt = 0;
		}
		else
		{
			cout << "\n\t\t\tPLAYER TWO WINS!\n";
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

	void mainMenu()
	{
		int decision;

		cout << "What would you like to do?\n\n" ;
		cout << "\t1) Get a new deck\n"          ;
		cout << "\t2) Show the deck\n"           ;
		cout << "\t3) How many cards are left?\n";
		cout << "\t4) Shuffle\n"                 ;
		cout << "\t5) Play WAR!\n"               ;
		cout << "\t6) Exit\n"                    ;
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
};