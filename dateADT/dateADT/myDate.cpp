/*Russell Tan
**CECS 282
**C++ For Java Programmers
**Date ADT Project Due Oct 2
**Student ID: 011529945
*/


#include "myDate.h"
#include <cmath>
myDate::myDate()
{
	month = 05;
	day = 11;
	year = 1959;
}
myDate::myDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}
void myDate::display()
{
	myDate thisDate = myDate(this->month,this->day,this->year);
	string months[12] = { "January", "February", "March", "April", "May",
						"June", "July", "August", "September", "October", 
						"November", "December" };
	if (!checkValid(thisDate))
	{
		myDate defaultDate = myDate();
		cout << months[defaultDate.getMonth() - 1] << " " << defaultDate.getDay() << ", " << defaultDate.getYear();
	}
	else
	{
		cout << months[month - 1] << " " << day << ", " << year;
	}
}
//convert to julian
//add days
//convert new value back to gregorian
void myDate::incrDate(int days)
{
	int julian;
	myDate tempDate = myDate(this->month,this->day,this->year);
	
	julian = days + this->gregToJulian(tempDate);
	this->julianToGreg(julian,month,day,year);
}
//convert to julian
//subtract days
//convert new value back to gregorian
void myDate::decrDate(int days)
{

	int julian;
	myDate tempDate = myDate(this->month, this->day, this->year);

	julian = this->gregToJulian(tempDate) - days;
	this->julianToGreg(julian, month, day, year);
}
//convert both to julian
//find difference between both
//return the difference
int myDate::daysBetween(myDate date)
{
	int daysBtwn;
	myDate temp = myDate(month, day, year);

	daysBtwn = gregToJulian(date) - gregToJulian(temp);
	return daysBtwn;
}
int myDate::getMonth()
{
	return month;
}
int myDate::getDay()
{
	return day;
}
int myDate::getYear()
{
	return year;
}
void myDate::setMonth(int m)
{
	month = m;
}
void myDate::setDay(int d)
{
	day = d;
}
void myDate::setYear(int y)
{
	year = y;
}
//convert date into julian
//find julian of date jan 1st, YEAR
//find absolute difference between date and second start date
int myDate::getYearOffset()
{
	int offset;
	myDate date = myDate(month, day, year);
	myDate janOffset = myDate(1, 1, date.getYear());

	offset = abs(gregToJulian(date)-gregToJulian(janOffset));

	return offset;
}
//store date
//convert to j
//convert back to g
//compare stored value with re-converted value
bool myDate::checkValid(myDate date)
{


	int jd;
	bool valid = false;
	myDate checker = date;

	jd = this->gregToJulian(date);

	date = this->julianToGreg(jd,date.month,date.day,date.year);
	if (checker.equals(date))
	{
		valid = true;
	}
	return valid;
}

bool myDate::equals(myDate date)
{
	return this->getDay() == date.getDay()
		&& this->getMonth() == date.getMonth()
		&& this->getYear() == date.getYear();
}
int myDate::gregToJulian(myDate date)
{
	int jd;
	int i = date.getYear();
	int j = date.getMonth();
	int k = date.getDay();

	jd = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
	return jd;
}
myDate myDate::julianToGreg(int jd, int &month, int &day, int &year)
{
	int i, j, k, l,n;
	myDate temp;

	l = jd + 68569;
	n = 4 * l / 146097;
	l = l - (146097 * n + 3) / 4;
	i = 4000 * (l + 1) / 1461001;
	l = l - 1461 * i / 4 + 31;
	j = 80 * l / 2447;
	k = l - 2447 * j / 80;
	l = j / 11;
	j = j + 2 - 12 * l;
	i = 100 * (n - 49) + i + l;

	year = i;
	month = j;
	day = k;
	temp = myDate(j, k, i);
	return temp;
}