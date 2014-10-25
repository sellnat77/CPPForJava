#include "myDate.h"
#include "UpDate.h"

UpDate::UpDate()
{
	myDate();
}
UpDate::UpDate(int m, int d, int y)
{
	myDate(m, d, y);

}

UpDate::~UpDate()
{

}

void UpDate::setDate(int m, int d, int y)
{
	myDate(m,d,y);
}
int UpDate::getMonth()
{
	return month;

}
int UpDate::getDay()
{
	return day;
}
int UpDate::getYear()
{
	return year;

}

string UpDate::getMonthName()
{
	switch (month)
	{
	case 1:
		return "January";
		break;
	case 2:
		return "February";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;
	default:
		break;
	}
}

UpDate UpDate::operator+(UpDate operand)
{


}
UpDate UpDate::operator+(int bogus)
{

}
UpDate UpDate::operator++()
{

}
UpDate UpDate::operator-(UpDate operand)
{

}
UpDate UpDate::operator-(int bogus)
{

}
UpDate UpDate::operator--()
{

}
UpDate UpDate::operator=(UpDate assign)
{

}
UpDate UpDate::operator>(UpDate compare)
{

}
UpDate UpDate::operator<(UpDate compare)
{

}
UpDate UpDate::operator==(UpDate compare)
{

}
UpDate UpDate::operator<<()
{

}