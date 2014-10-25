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

	int getMonth();
	int getDay();
	int getYear();

	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);

	void display();

	void incrDate(int days);
	void decrDate(int days);


	bool checkValid(myDate date);
	bool equals(myDate date);

	int daysBetween(myDate date);
	int getYearOffset();
	int gregToJulian(myDate date);

	myDate julianToGreg(int jd, int &month, int &day, int &year);
};
#endif