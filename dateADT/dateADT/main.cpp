// testdate.cpp
// Author: Steven H Gold
// Program #2 due date: 10/2/2014
// 
//
// All rights and lefts reserved.
//

#include "myDate.h"
#include <iostream>
using namespace std;

int main()
{
	myDate Bday;
	myDate duedate(10, 2, 2014);

	int x;
	int month, day, year;

	Bday.display();
	cout << endl;
	duedate.display();
	cout << endl;
	x = Bday.daysBetween(duedate);
	cout << "Master Gold is " << x << " days old today";
	cout << endl;

	Bday.incrDate(x);

	cout << "Now these 2 dates should be the same:";
	Bday.display();
	cout << '\t';
	duedate.display();
	cout << "\n\n";


	month = duedate.getMonth();
	day = duedate.getDay();
	year = duedate.getYear();

	duedate.display();
	cout << " is also equal to " << month << "/" << day << "/" << year << endl;

	myDate July4(7, 4, 2014);
	cout << "This year the 4th of July will happen " << July4.getYearOffset() << "days after New Years\n\n";

	myDate bogus(23, 12, 2007);
	cout << "The value of the bogus date is:";
	bogus.display();
	cout << endl;

	myDate D5(8, 21, 2007);
	x = D5.getYearOffset();
	D5.decrDate(x);
	cout << "Happy Newyear 2007 happened on:";
	D5.display();
	cout << endl;

	return 0;
}



