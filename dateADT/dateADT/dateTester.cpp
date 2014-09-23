#include "myDate.h""

int main()
{
	myDate date = myDate();

	date.display();
	cout << "\nJulian date:" << date.gregToJulian(date) << "\n";
	date.incDate(366);
	date.display();
	cout << "\nJulian date:" << date.gregToJulian(date) << "\n";
	return 0;
}