// testupDate.cpp
// Author: Steven H Gold
// Program #4 due date: 11/04/2014
// 
// 
//
// All rights and lefts reserved.
//

#include "upDate.h"
#include "myDate.h"
#include <iostream>
using namespace std;

int main()
{
	upDate Bday;
	upDate duedate(11, 04, 2014);

	int x;
	int month, day, year;


	cout << endl;
	cout << "This program is due on " << duedate;
	cout << endl;

	/*cout << "Right now there are " << upDate::GetDateCount() << "upDate objects\n";
	{
		upDate d1, d2, d3;
		cout << "Inside this block there are " << upDate::GetDateCount() << "upDate objects\n";
	}
	*/
	//cout << "Outside the block there are " << upDate::GetDateCount() << "upDate objects\n";
	upDate dtemp(duedate);
	dtemp++;
	cout << "If you turn this assignment in on " << dtemp << " then is will be late\n";
	cout << "it is due on " << --dtemp << " so don't be late\n";
	cout << "one week from due date is " << duedate + 7 << endl;
	cout << "one week from due date is " << 7 + duedate << endl;
	cout << "one week earlier from due date is " << duedate - 7 << endl;

	cout << "Your professor was born on " << Bday << " : ";
	cout << "Doctor Gold (oh please...) is " << duedate - Bday << " days old today\n";

	cout << "Today is Julian date " << duedate.julian();

	upDate testdate(11, 04, 2014);
	upDate monday(duedate);
	monday--;
	cout << "Monday was " << monday;
	upDate springBreak(monday + 7);
	cout << "Spring Break begins " << springBreak << endl;
	springBreak.~upDate();
	cout << "Today is " << duedate << " and the test will be on " << testdate << endl;



	return 0;
}



