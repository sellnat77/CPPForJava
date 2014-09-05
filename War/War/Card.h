#include <iostream>
#include <string>

using namespace std;
class Card
{

private:
	int rank;
	string suit;
	string face;

public:
	Card();

	Card(string s);
	Card(int r, string s);	
	Card(int r, string s, string f);
	Card(string face, string s);

	int getValue();

	string getSuit();
	string getFace();

	void displayCard();
	void setValue(int r);
	void setCard (int r);
	void setCard (int r, string s);
	void setCard (int r, string s, string f);
	
};