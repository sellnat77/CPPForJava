#include <iostream>


#ifndef CARD_H_
#define CARD_H_
using namespace std;
class Card
{
private:
	char rank;
	char suit;
public:
	Card();
	Card(char, char);

	void setRank(char);
	void setSuit(char);

	char getRank();
	char getSuit();

	void displayCard();
};
#endif