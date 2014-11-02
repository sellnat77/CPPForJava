#include <iostream>
#include <string>
using namespace std;

#ifndef upDate_H
#define upDate_H
class upDate
{
private:
	int *date; 
	
	


public:

	upDate();
	upDate(int m, int d, int y);
	upDate(upDate&);

	~upDate();

	void setDate(int m, int d, int y);
	void display();
	int getMonth();
	int getDay();
	int getYear();

	string getMonthName();
	static int GetDateCount();

	friend upDate operator+(int,upDate);
	friend upDate operator+(upDate,int);
	
	
	upDate& operator++();
	upDate operator++(int);
	
	
	friend int operator-(upDate,upDate);
	friend upDate operator-(int,upDate);
	friend upDate operator-(upDate,int);
	
	
	upDate& operator--();
	upDate operator--(int);
	
	upDate operator=(upDate);
	upDate operator>(upDate);
	upDate operator<(upDate);
	upDate operator==(upDate);
	friend ostream &operator<<(ostream&,upDate&);

	int julian();


};
#endif