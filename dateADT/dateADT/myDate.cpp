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
}