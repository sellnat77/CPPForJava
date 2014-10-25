#include <iostream>
#include <string>
using namespace std;

#ifndef UPDATE_H
#define UPDATE_H
class UpDate
{
private:
	int month;
	int day;
	int year;

public:
	UpDate();
	UpDate(int m, int d, int y);

	~UpDate();

	void setDate(int m, int d, int y);
	int getMonth();
	int getDay();
	int getYear();

	string getMonthName();

	UpDate operator+(UpDate);
	UpDate operator+(int);
	UpDate operator++();
	UpDate operator-(UpDate);
	UpDate operator-(int);
	UpDate operator--();
	UpDate operator=(UpDate );
	UpDate operator>(UpDate );
	UpDate operator<(UpDate );
	UpDate operator==(UpDate );
	UpDate operator<<();

};
#endif