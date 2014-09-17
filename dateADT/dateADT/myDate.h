#include <iostream>
using namespace std;

#ifndef MYDATE_H
#define MYDATE_H

class myDate
{
private:
	int month;
	int day;
	int year;
public:
	myDate();
	myDate(int m, int d, int y);
	void display();
	void incDate();
	void decDate();
	int daysBetween(myDate date);
	int getMonth();
	int getDay();
	int getYear();
	int getYearOffset();
};
#endif