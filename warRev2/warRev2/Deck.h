#include "Card.h"
class Deck
{
private:
	Card allCards[52];
	int cardsDealt;
public:
	Deck();

	Card deal();
	int cardsLeft();
	void shuffle();
	void displayCardAt();
	void showAllCards();
	
	
};