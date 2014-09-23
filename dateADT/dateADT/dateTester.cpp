#include "myDate.h""

int main()
{
	myDate date = myDate();
	myDate anotherDate = myDate(2, 30, 1992);
	int mo, d, ye;
	mo = 2;
	d = 30;
	ye = 1992;

	date.display();
	cout << "\nJulian date:" << date.gregToJulian(date) << "\n";
	date.incDate(51);
	date.display();
	cout << "\nJulian date:" << date.gregToJulian(date) << "\n";
	date = myDate(1, 10, 1959);
	cout << "\n\nYear off set from ";
	date.display();
	cout << "\t" << date.getYearOffset(date);

	cout << "\n\t\tDays between ";
	date.display();
	cout << " and ";
	anotherDate.display();

	cout << "\n\n" << date.daysBetween(anotherDate);

	anotherDate.display();
	anotherDate.julianToGreg(anotherDate.gregToJulian(anotherDate), mo,d,ye);
	anotherDate.display();

	cout << "\n\n\n\n";
	return 0;
}