#include "myDate.h"
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
	string months[12] = { "January", "February", "March", "April", "May",
						"June", "July", "August", "September", "October", 
						"November", "December" };
	cout << months[month] << " " << day << ", " << year;
}
void myDate::incDate(int days)
{
	//convrt to julian
	//add days
	//convert new value back to gregorian
}
void myDate::decDate()
{
	//convrt to julian
	//subtract days
	//convert new value back to gregorian
}
int myDate::daysBetween(myDate date)
{
	//convert both to julian
	//find difference between both
	//use absolute value
	//return the absolute difference
	return 0;
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
int myDate::getYearOffset()
{
	//convert date into julian
	//find julian of date jan 1st, YEAR
	//find absolute difference between date and second start date
	return 0;
}
int myDate::gregToJulian(int m, int d, int y)
{
	int jd;
	int i = y;
	int j = m;
	int k = d;

	jd = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
	return jd;
}
void myDate::setJulianToGreg(int jd)
{
	int i, j, k, l,n;

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
}