#include <iostream>
#include <string>
using namespace std;

#ifndef UPDATE_H
#define UPDATE_H
class UpDate
{
private:
public:
	UpDate();
	UpDate(int m, int d, int y);

	~UpDate();

	void setDate();
	int getMonth();
	int getDay();
	int getYear();

	string getMonthName();

	UpDate operator+();
	UpDate operator+(int bogus);
	UpDate operator-();
	UpDate operator-(int bogus);
	UpDate operator=(UpDate assign);
	UpDate operator>(UpDate compare);
	UpDate operator<(UpDate compare);
	UpDate operator==(UpDate compare);

};
#endif