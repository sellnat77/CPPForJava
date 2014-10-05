#include "myDate.h"

struct Student
{
	int grade;
	char name[10];
	int id;
	myDate bday;

};

int main()
{
	Student s1;

	s1.grade = 72;
	strcpy_s(s1.name, "Torino");
	s1.id = 1013;
	s1.bday = myDate(10, 02, 1992);

	s1.bday.display();
}