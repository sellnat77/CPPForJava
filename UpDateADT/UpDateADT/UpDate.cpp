#include "myDate.h"
#include "upDate.h"

upDate::upDate()
{
	myDate();
}
upDate::upDate(int m, int d, int y)
{
	myDate(m, d, y);

}

upDate::~upDate()
{

}

void upDate::setDate(int m, int d, int y)
{
	myDate(m,d,y);
}

void upDate::display()
{

}
int upDate::getMonth()
{
	return month;

}
int upDate::getDay()
{
	return day;
}
int upDate::getYear()
{
	return year;

}

string upDate::getMonthName()
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

upDate upDate::operator+(upDate operand)
{


}
upDate upDate::operator+(int bogus)
{

}
upDate upDate::operator++()
{

}
upDate upDate::operator-(upDate operand)
{

}
upDate upDate::operator-(int bogus)
{

}
upDate upDate::operator--()
{

}
upDate upDate::operator=(upDate assign)
{

}
upDate upDate::operator>(upDate compare)
{

}
upDate upDate::operator<(upDate compare)
{

}
upDate upDate::operator==(upDate compare)
{

}
ostream upDate::operator<<(upDate print)
{
	print.display();
}