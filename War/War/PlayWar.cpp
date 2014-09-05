#include "CardDeck.h"

int main()
{
	int k,decision,playerOneScore, playerTwoScore;
	bool playAgain = true;
	bool tie,playerOnesTurn;
	CardDeck warGame;

	warGame.newDeck();
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
			warGame = CardDeck();
			warGame.setCardsDealt(0);
			break;

		case 2:
			warGame.showAllCards();
			break;

		case 3:
			cout << "There are " << warGame.cardsLeft() << " cards left.\n";
			break;

		case 4:
			warGame.shuffle();
			break;

		case 5:
			warGame.playWar();
			break;

		default:
			cout << "Thanks for playing!\n";
			playAgain = false;
			break;
		}















		/*playerOneScore = 0;
		playerTwoScore = 0;
		playerOnesTurn = true;
		tie = false;

		for (k = 0; k < 4; k++)
		{
			if (playerOnesTurn)
			{
				cout << "\nPlayer one draws...\t";
				playerOneScore += war.dealCard();
				war.incCardsDealt(1);
				system("pause");
				playerOnesTurn = false;
			}
			else
			{
				cout << "\nPlayer two draws...\t";
				playerTwoScore += war.dealCard();
				war.incCardsDealt(1);
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
			if (war.getCardsDealt() == 52)
			{
				cout << "Not enough cards! grabbing new shuffled deck...";
				CardDeck();
				war.setCardsDealt(0);
			}
			else
			{
				cout << "\n\t\t\tTIE! Play again!\n";
				tie = true;
				//need to return to top of while loop here somehow
			}
		}
		else if (war.getCardsDealt() == 52)
		{
			cout << "Not enough cards! grabbing new shuffled deck...\n";
			CardDeck();
			war.setCardsDealt(0);
		}
		else
		{
			cout << "\n\t\t\tPLAYER TWO WINS!\n";
		}

		cout << "There are " << war.cardsLeft() << "cards left.\n";
		cout << "Want to play again? 1)yes 2)no ";

		cin >> decision;

		if (decision != 1)
		{
			playAgain = false;
		}
		*/

	}

	//war.mainMenu();

	return 0;
}