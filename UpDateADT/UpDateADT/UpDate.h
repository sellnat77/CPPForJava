#include <iostream>
#include <string>
using namespace std;

#ifndef upDate_H
#define upDate_H
class upDate
{
private:
	int *date;
	static int count;

public:
	upDate();
	upDate(int m, int d, int y);
	upDate(upDate&);
	~upDate();

	static int GetDateCount();
	
	int getMonth();
	int getDay();
	int getYear();
	int julian();
	void setDate(int m, int d, int y);	

	friend upDate operator+(int,upDate);
	friend upDate operator+(upDate,int);
	
	upDate& operator++();
	upDate operator++(int);
	
	friend int operator-(upDate,upDate);
	friend upDate operator-(int,upDate);
	friend upDate operator-(upDate,int);
	
	upDate& operator--();
	upDate operator--(int);
	
	friend ostream &operator<<(ostream&,upDate&);
};
#endif