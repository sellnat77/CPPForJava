#include "Deck.h"

int main()
{
	//Initialize the variables to keep track of progress
	//in game
	int k,decision,rematchChoice;
	int cardsDealt  = 0;
	int playerOne   = 0;
	int computer    = 0;
	bool rematch    = true;
	bool playAgain  = true;
	bool playerTurn = true;	

	//Get a new deck
	Deck myGame = Deck();

	//Loop to allow user to revisit the main menu
	while (playAgain)
	{
		//Display menu
		myGame.centerText("What would you like to do?");
		cout << "\n\t1) Get a new deck\n";
		cout << "\t2) Show the deck\n";
		cout << "\t3) How many cards are left?\n";
		cout << "\t4) Shuffle\n";
		cout << "\t5) Play WAR!\n";
		cout << "\t6) Exit\n";

		//Checks if user input a number 
		//value put through switch to 
		//determine next method
		while (!(cin >> decision))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter a number.";
		}

		switch (decision)
		{
		case 1://Grab a new deck
			system("cls");
			myGame.centerText("You have a new, unshuffled deck.");
			system("pause");
			cardsDealt = 0;
			myGame = Deck();
			system("cls");
			break;

		case 2://Show the current deck
			system("cls");
			myGame.showAllCards();
			break;

		case 3://Show how many cards are left
			system("cls");
			cout << "\t\t\tThere are " << myGame.cardsLeft() << " cards left.\n";
			system("pause");
			system("cls");
			break;

		case 4://Shuffle the deck
			system("cls");
			myGame.centerText("Shuffling the deck...");
			myGame.shuffle();
			system("pause");
			system("cls");
			break;

		case 5://Play war
			rematch = true;

			//Allow user to rematch
			while (rematch)
			{
				rematch = false;

				//Deal and display cards to player and computer
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
				
				//Show scores after match
				cout << "\t\t\t\tYour Score = " << playerOne << "\n";
				cout << "\t\t\t\tComputer   = " << computer  << "\n";

				if (playerOne > computer)//Player win
				{
					myGame.centerText("PLAYER ONE WINS!");
					cout << "\n\n\n\n";
					if (cardsDealt == 52)//If the deck has been dealt, get a new shuffled one
					{
						myGame.centerText("Not enough cards! grabbing new shuffled deck...");
						myGame = Deck();
						myGame.shuffle();
						cardsDealt = 0;
					}

					//Show how many cards are left and ask for rematch
					cout << "\t\t\t    There are " << myGame.cardsLeft() << " cards left.\n";
					myGame.centerText("Would you like a rematch?");
					myGame.centerText("Enter 1 for yes and 2 for no");
					
					//Ensures (int) input sets rematch to true to loop through deal process again
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
				else if (playerOne == computer)//Tie game
				{
					if (cardsDealt == 52)//If deck has been dealt, grab a shuffled one
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
				else//Computer wins
				{
					myGame.centerText("COMPUTER WINS!");
					cout << "\n\n\n\n";
					if (cardsDealt == 52)//If deck has been dealt grab a shuffled one
					{
						myGame.centerText("Not enough cards! grabbing new shuffled deck...");
						myGame = Deck();
						myGame.shuffle();
						cardsDealt = 0;
					}

					//Ensures (int) input sets rematch to true to loop through deal process again
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
				//Resets the scores
				playerOne = 0;
				computer = 0;
			}
			break;

		default://Exit the program
			myGame.centerText("Thanks for playing!");
			playAgain = false;
			break;
		}
	}
	return 0;
};