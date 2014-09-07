#include "Deck.h"

int main()
{
	int k,decision,rematchChoice;
	int cardsDealt  = 0;
	int playerOne   = 0;
	int computer    = 0;
	bool rematch    = true;
	bool playAgain  = true;
	bool playerTurn = true;	

	Deck myGame = Deck();

	while (playAgain)
	{
		myGame.centerText("What would you like to do?");
		cout << "\n\t1) Get a new deck\n";
		cout << "\t2) Show the deck\n";
		cout << "\t3) How many cards are left?\n";
		cout << "\t4) Shuffle\n";
		cout << "\t5) Play WAR!\n";
		cout << "\t6) Exit\n";

		while (!(cin >> decision))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a number.";
		}

		switch (decision)
		{
		case 1:
			system("cls");
			myGame.centerText("You have a new, unshuffled deck.");
			system("pause");
			cardsDealt = 0;
			myGame = Deck();
			system("cls");
			break;

		case 2:
			system("cls");
			myGame.showAllCards();
			break;

		case 3:
			system("cls");
			cout << "\t\t\tThere are " << myGame.cardsLeft() << " cards left.\n";
			system("pause");
			system("cls");
			break;

		case 4:
			system("cls");
			myGame.centerText("Shuffling the deck...");
			myGame.shuffle();
			system("pause");
			system("cls");
			break;

		case 5:
			rematch = true;
			while (rematch)
			{
				rematch = false;
				myGame.centerText("Dealing, prepare for WAR!");
				for (k = 0; k < 4; k++)
				{
					if (playerTurn)
					{
						cout << "\nYou draw...      \t";
						playerOne += myGame.deal().getValue();
						cardsDealt++;
						system("pause");
						playerTurn = false;
					}
					else
					{
						cout << "\nComputer draws...\t";
						computer += myGame.deal().getValue();
						cardsDealt++;
						system("pause");
						cout << "\n\n";
						playerTurn = true;
					}
				}
				
				cout << "\t\t\t\tYour Score = " << playerOne << "\n";
				cout << "\t\t\t\tComputer   = " << computer  << "\n";

				if (playerOne > computer)
				{
					myGame.centerText("PLAYER ONE WINS!");
					cout << "\n\n\n\n";
					if (cardsDealt == 52)
					{
						myGame.centerText("Not enough cards! grabbing new shuffled deck...");
						myGame = Deck();
						myGame.shuffle();
						cardsDealt = 0;
					}

					cout << "\t\t\t    There are " << myGame.cardsLeft() << " cards left.\n";
					myGame.centerText("Would you like a rematch?");
					myGame.centerText("Enter 1 for yes and 2 for no");
					
					while (!(cin >> rematchChoice))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						myGame.centerText("Enter a number.");
					}

					if (rematchChoice == 1)
					{
						rematch = true;
					}
					else
					{
						system("cls");
					}
				}
				else if (playerOne == computer)
				{
					if (cardsDealt == 52)
					{
						myGame.centerText("TIE!");
						cout << "\n\n\n\n";
						myGame.centerText("Not enough cards! grabbing new shuffled deck...");
						myGame = Deck();
						myGame.shuffle();
						cardsDealt = 0;
						rematch = true;
					}
					else 
					{
						myGame.centerText("TIE! Play again!");
						rematch = true;
					}
				}
				else
				{
					myGame.centerText("PLAYER TWO WINS!");
					cout << "\n\n\n\n";
					if (cardsDealt == 52)
					{
						myGame.centerText("Not enough cards! grabbing new shuffled deck...");
						myGame = Deck();
						myGame.shuffle();
						cardsDealt = 0;
					}

					cout << "\t\t\t    There are " << myGame.cardsLeft() << " cards left.\n";
					myGame.centerText("Would you like a rematch?");
					myGame.centerText("Enter 1 for yes and 2 for no");
					while (!(cin >> rematchChoice))
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Enter a number.";
					}
					if (rematchChoice == 1)
					{
						rematch = true;
					}
					else
					{
						system("cls");
					}

				}
				playerOne = 0;
				computer = 0;
			}
			break;

		default:
			myGame.centerText("Thanks for playing!");
			playAgain = false;
			break;
		}
	}
	return 0;
};