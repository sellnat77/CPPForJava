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

	int dealCard     ();
	int cardsLeft    ();
	int getCardsDealt();
	int getPlayerOneScore();
	int getPlayerTwoScore();

	void newDeck();
	void shuffle      ();
	void showAllCards ();
	void playWar      ();
	void checkScore   ();
	void mainMenu     ();
	void setPlayerOneScore(int s);
	void setPlayerTwoScore(int s);
	void incPlayerOne(int s);
	void incPlayerTwo(int s);
	void setCardsDealt(int c);
	void incCardsDealt(int c);
	void displayCardAt(int location);
};