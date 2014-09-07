#include "Deck.h"

int main()
{
	int k,decision;
	int cardsDealt = 0;
	int playerOne = 0;
	int computer = 0;
	bool playAgain = true;
	bool playerTurn = true;
	bool rematch = true;

	Deck myGame = Deck();
	while (playAgain)
	{
		cout << "What would you like to do?\n\n";
		cout << "\t1) Get a new deck\n";
		cout << "\t2) Show the deck\n";
		cout << "\t3) How many cards are left?\n";
		cout << "\t4) Shuffle\n";
		cout << "\t5) Play WAR!\n";
		cout << "\t6) Exit\n";

		//cin >> decision;
		while (!(cin >> decision))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a number ya dingus!";
		}
		switch (decision)
		{
		case 1:
			cardsDealt = 0;
			myGame = Deck();
			break;

		case 2:
			myGame.showAllCards();
			break;

		case 3:
			cout << "There are " << myGame.cardsLeft() << " cards left.\n";
			break;

		case 4:
			myGame.shuffle();
			break;

		case 5:
			rematch = true;
			while (rematch)
			{
				rematch = false;
				cout << "\tDealing, prepare for WAR!\n";
				for (k = 0; k < 4; k++)
				{
					if (playerTurn)
					{
						cout << "You draw...\t";
						playerOne += myGame.deal().getValue();
						cardsDealt++;
						system("pause");
						playerTurn = false;
					}
					else
					{
						cout << "Computer draws...\t";
						computer += myGame.deal().getValue();
						cardsDealt++;
						system("pause");
						playerTurn = true;
					}
				}

				cout << "\t\tYour Score = " << playerOne << "\n";
				cout << "\t\tComputer   = " << computer << "\n";

				if (playerOne > computer)
				{
					cout << "\n\t\t\tPLAYER ONE WINS!\n";
					if (cardsDealt == 52)
					{
						cout << "Not enough cards! grabbing new deck...";
						myGame = Deck();
						cardsDealt = 0;

					}
				}
				else if (playerOne == computer)
				{
					if (cardsDealt == 52)
					{
						cout << "\n\t\t\tTIE!\n";
						cout << "Not enough cards! grabbing new shuffled deck...\n";
						myGame = Deck();
						myGame.shuffle();
						cardsDealt = 0;
						rematch = true;
					}
					else 
					{
						cout << "\n\t\t\tTIE! Play again!\n";
						rematch = true;
					}
				}
				else
				{
					cout << "\n\t\t\tPLAYER TWO WINS!\n";
					if (cardsDealt == 52)
					{
						cout << "Not enough cards! grabbing new deck...\n";
						myGame = Deck();
						cardsDealt = 0;
					}

				}
				playerOne = 0;
				computer = 0;
				cout << "\t\t\t\n\n\nCards dealt: " << cardsDealt;
			}
			break;

		default:
			cout << "Thanks for playing!\n";
			playAgain = false;
			break;
		}
	}


	return 0;
};