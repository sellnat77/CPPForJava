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
	string months[12] = { "January", "February", "March", "April", "May",
						"June", "July", "August", "September", "October", 
						"November", "December" };
	cout << months[month - 1] << " " << day << ", " << year;
	/*if (checkValid(this))
	{
		cout << months[month - 1] << " " << day << ", " << year;
	}
	else
	{
		cout << "NO!";
	}
	*/
}
void myDate::incDate(int days)
{
	int julian;
	myDate comparison;
	myDate tempDate = myDate(this->month,this->day,this->year);
	//convert to julian
	//add days
	//convert new value back to gregorian
	//if it is a valid date

	julian = days + this->gregToJulian(tempDate);
	this->julianToGreg(julian,month,day,year);
	//if (!checkValid(tempDate))
	//{
	//	cout << "Date not valid";
	//}	
}
void myDate::decDate()
{
	//convert to julian
	//subtract days
	//convert new value back to gregorian
}
int myDate::daysBetween(myDate date)
{
	int daysBtwn;
	myDate temp = myDate(month, day, year);
	//convert both to julian
	//find difference between both
	//use absolute value
	//return the absolute difference

	daysBtwn = abs(gregToJulian(temp) - gregToJulian(date));
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
int myDate::getYearOffset(myDate date)
{
	int offset;
	myDate janOffset = myDate(1, 1, date.getYear());
	//convert date into julian
	//find julian of date jan 1st, YEAR
	//find absolute difference between date and second start date

	offset = abs(gregToJulian(date)-gregToJulian(janOffset));

	return offset;
}
bool myDate::checkValid(myDate date)
{
	//store date
	//convert to j
	//convert back to g
	//compare stored value with re-converted value

	int jd, month, day, year, tmonth, tday, tyear;
	bool valid = true;
	month = date.getMonth();
	day = date.getDay();
	year = date.getYear();
	tmonth = date.getMonth();
	tday = date.getDay();
	tyear = date.getYear();

	jd = this->gregToJulian(date);
	this->julianToGreg(jd, tmonth, tday, tyear);
	if (month == tmonth && day == tday && year == tyear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool myDate::equals(myDate date)
{
	if (this->getDay() == date.getDay()
		&& this->getMonth() == date.getMonth()
		&& this->getYear() == date.getYear())
	{
		return true;
	}
	else
	{
		return false;
	}
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
void myDate::julianToGreg(int jd, int &month, int &day, int &year)
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