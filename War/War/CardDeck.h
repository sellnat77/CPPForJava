#include "Card.h"

class CardDeck
{

private:
	Card war[52];
	int playerOneScore = 0;
	int playerTwoScore = 0;
	int cardsDealt     = 0;

public:
	CardDeck();	

	void displayCardAt(int location);

	int dealCard     ();

	int cardsLeft    ();

	void shuffle     ();

	void showAllCards();

	void playWar     ();

	void mainMenu    ();
};