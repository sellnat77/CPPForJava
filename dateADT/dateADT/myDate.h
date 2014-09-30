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
	void decDate(int days);
	int daysBetween(myDate date);
	int getMonth();
	int getDay();
	int getYear();
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);
	int getYearOffset(myDate date);
	bool checkValid(myDate date);
	bool equals(myDate date);
	int gregToJulian(myDate date);
	myDate julianToGreg(int jd, int &month, int &day, int &year);
};
#endif