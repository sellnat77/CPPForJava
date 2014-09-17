#include <iostream>
#include <string>
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
	void incDate(int days);
	void decDate();
	int daysBetween(myDate date);
	int getMonth();
	int getDay();
	int getYear();
	int setMonth(int m);
	int setDay(int d);
	int setYear(int y);
	int getYearOffset();
	bool checkValid(myDate date);
	int gregToJulian(int m, int d, int y);
	myDate julianToGreg(int jd);
};
#endif