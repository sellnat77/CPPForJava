#include <iostream>
#include <string>
using namespace std;

#ifndef upDate_H
#define upDate_H
class upDate
{
private:
	int month;
	int day;
	int year;


public:
	upDate();
	upDate(int m, int d, int y);

	~upDate();

	void setDate(int m, int d, int y);
	void display();
	int getMonth();
	int getDay();
	int getYear();

	string getMonthName();

	upDate operator+(upDate);
	upDate operator+(int);
	upDate operator++();
	upDate operator-(upDate);
	friend upDate operator-(myDate);
	upDate operator--();
	upDate operator=(upDate );
	upDate operator>(upDate );
	upDate operator<(upDate );
	upDate operator==(upDate );
	&ostream operator<<(ostream,&upDate);


};
#endif