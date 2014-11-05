#include "upDate.h"
#include "myDate.h"

int upDate::count = 0;
upDate::upDate()
{
	count++;
	date = new int[3];
	date[0] = 5;
	date[1] = 11;
	date[2] = 1959;
}
upDate::upDate(int m, int d, int y)
{
	count++;
	date = new int[3];
	date[0] = m;
	date[1] = d;
	date[2] = y;
}
upDate::upDate(upDate& source)
{
	count++;
	date = new int[3];
	date[0] = source.date[0];
	date[1] = source.date[1];
	date[2] = source.date[2];
}
upDate::~upDate()
{
	count--;
	delete []date;
	date = 0;
}
int upDate::GetDateCount()
{
	return count;
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
int upDate::julian()
{
	int jd;
	int i = date[2];
	int j = date[0];
	int k = date[1];

	jd = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
	return jd;
}
void upDate::setDate(int m, int d, int y)
{
	myDate(m,d,y);
}
upDate operator+(int bogus,upDate operand)
{
	myDate dTemp = myDate(operand.date[0], operand.date[1], operand.date[2]);
	int temp = dTemp.gregToJulian(dTemp);
	temp += bogus;
	dTemp.julianToGreg(temp, operand.date[0], operand.date[1], operand.date[2]);
	return operand;
}
upDate operator+(upDate operand,int bogus)
{
	myDate dTemp = myDate(operand.date[0], operand.date[1], operand.date[2]);
	int temp = dTemp.gregToJulian(dTemp);
	temp += bogus;
	dTemp.julianToGreg(temp, operand.date[0], operand.date[1], operand.date[2]);
	return operand;
}
upDate& upDate::operator++()
{
	myDate temp = myDate(this->date[0], this->date[1], this->date[2]);
	int tDate;
	tDate = temp.gregToJulian(temp);
	++tDate;
	temp.julianToGreg(tDate, this->date[0], this->date[1], this->date[2]);
	return *this;
}
upDate upDate::operator++(int bogus)
{
	myDate temp = myDate(this->date[0], this->date[1], this->date[2]);
	int tDate;

	tDate = this->julian();

	tDate++;
	temp.julianToGreg(tDate, this->date[0], this->date[1], this->date[2]);
	
	return *this;
}
int operator-(upDate operand,upDate temp)
{
	int diff;
	diff = operand.julian() - temp.julian();
	return diff;
}
upDate operator-(int bogus,upDate operand)
{
	myDate dTemp = myDate(operand.date[0], operand.date[1], operand.date[2]);
	int temp = dTemp.gregToJulian(dTemp);
	temp += bogus;
	dTemp.julianToGreg(temp, operand.date[0], operand.date[1], operand.date[2]);
	return operand;
}
upDate operator-(upDate operand, int bogus)
{
	myDate dTemp = myDate(operand.date[0], operand.date[1], operand.date[2]);
	int temp = dTemp.gregToJulian(dTemp);
	temp -= bogus;
	dTemp.julianToGreg(temp, operand.date[0], operand.date[1], operand.date[2]);
	return operand;
}
upDate& upDate::operator--()
{
	myDate temp = myDate(this->date[0], this->date[1], this->date[2]);
	int tDate;
	tDate = temp.gregToJulian(temp);
	--tDate;
	temp.julianToGreg(tDate, this->date[0], this->date[1], this->date[2]);
	return *this;
}
upDate upDate::operator--(int bogus)
{
	myDate temp = myDate(this->date[0], this->date[1], this->date[2]);
	int tDate;
	tDate = temp.gregToJulian(temp);
	tDate--;
	temp.julianToGreg(tDate, this->date[0], this->date[1], this->date[2]);
	return *this;
}
ostream& operator<<(ostream& os,upDate& print)
{
	os << print.date[0] << '/' << print.date[1] << '/' << print.date[2];
	return os;
}
