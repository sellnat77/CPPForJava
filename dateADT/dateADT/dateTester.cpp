#include "myDate.h""

int main()
{
	myDate valid = myDate();
	myDate invalid = myDate(2, 20, 2014);

	cout << valid.checkValid(valid);
	cout <<	invalid.checkValid(invalid);

	cout << "\n\nInitial date:\n\n";
	invalid.display();
	cout << "\n\nIncreasing date by 9 days:\n\n";
	invalid.incDate(9);
	cout << "\n\nNew date after increasing by 9:\n\n";
	invalid.display();
	cout << "\n\nDecreasing by 9 days:\n\n";
	invalid.decDate(9);
	cout << "\n\nShould be same as original date:\n\n";
	invalid.display();
	cout << "\n\n";


	return 0;
}