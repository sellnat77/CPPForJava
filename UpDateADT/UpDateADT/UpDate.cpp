#include "upDate.h"
#include "myDate.h"


upDate::upDate()
{
	date = new int[3];
	myDate();
}
upDate::upDate(int m, int d, int y)
{
	myDate theDate = myDate(m, d, y);
	date = new int[3];
	date[0] = theDate.getMonth();
	date[1] = theDate.getDay();
	date[2] = theDate.getYear();
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
	return date[0];

}
int upDate::getDay()
{
	return date[1];
}
int upDate::getYear()
{
	return date[2];

}

static int GetDateCount()
{
	return 1;
}

string upDate::getMonthName()
{
	switch (date[0])
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

upDate operator+(upDate operand)
{
	return operand;

}
upDate operator+(upDate temp,int bogus)
{
	return temp;
}
upDate operator++(upDate temp)
{
	return temp;
}
upDate operator++(upDate temp, int bogus)
{
	return temp;
}
upDate operator-(upDate operand,upDate temp)
{
	return operand;
}
upDate operator-(upDate one)
{
	return one;
}
upDate operator-(upDate temp, int bogus)
{
	return temp;
}
upDate upDate::operator--()
{
	return *this;
}
upDate upDate::operator=(upDate assign)
{
	return assign;
}
upDate upDate::operator>(upDate compare)
{
	return compare;
}
upDate upDate::operator<(upDate compare)
{
	return compare;
}
upDate upDate::operator==(upDate compare)
{
	return compare;
}
ostream& operator<<(ostream& os,upDate& print)
{
	os << print.date[0] << '/' << print.date[1] << '/' << print.date[2];
	return os;
}

int upDate::julian()
{
	int jd;
	int i = date[2];
	int j = date[0];
	int k = date[1];

	jd = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
	return jd;
}
upDate::~upDate()
{
	delete date;
}