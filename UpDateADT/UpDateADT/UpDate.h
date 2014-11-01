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

	~upDate();

	void setDate(int m, int d, int y);
	void display();
	int getMonth();
	int getDay();
	int getYear();

	string getMonthName();
	static string GetDateCount();

	upDate operator+(upDate);
	upDate operator+(int);
	upDate operator++();
	upDate operator-(upDate);
	//upDate operator-(upDate);
	upDate operator--();
	upDate operator=(upDate );
	upDate operator>(upDate );
	upDate operator<(upDate );
	upDate operator==(upDate );
	friend ostream &operator<<(ostream&,upDate&);

	int julian();


};
#endif