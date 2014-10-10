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
	Student theClass[10];
	Student *byGrade[10];
	Student *byName[10];
	Student *byId[10];
	Student *byBday[10];
	int k;

	for (k = 0; k < 10; k++)
	{
		byGrade[k] = &theClass[k];
		byName[k] = &theClass[k];
		byId[k] = &theClass[k];
		byBday[k] = &theClass[k];
	}


}