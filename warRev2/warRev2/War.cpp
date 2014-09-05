#include "Deck.h"

int main()
{
	int k,decision;
	int playerOne = 0;
	int computer = 0;
	bool playAgain = true;
	bool playerTurn = true;

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

		cin >> decision;
		switch (decision)
		{
		case 1:
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
			//myGame.playWar();
			break;

		default:
			cout << "Thanks for playing!\n";
			playAgain = false;
			break;
		}
	}


	return 0;
};