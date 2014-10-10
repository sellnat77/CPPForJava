#include "myDate.h"

struct Student
{
	int grade;
	char name[10];
	int id;
	myDate bday;

};


void display(Student var)
{
	cout << "Name: " << var.name << "\t\t";
	cout << "Grade   : " << var.grade << "\n";
	
	cout << "ID  : " << var.id << "\t\t";
	cout << "Birthday: ";
	var.bday.display();
	cout << "\n\n";
}

int main()
{
	Student theClass[10];
	Student *byGrade[10];
	Student *byName[10];
	Student *byId[10];
	Student *byBday[10];
	int k;

	theClass[0].grade = 67;
	theClass[1].grade = 70;
	theClass[2].grade = 98;
	theClass[3].grade = 75;
	theClass[4].grade = 50;
	theClass[5].grade = 89;
	theClass[6].grade = 80;
	theClass[7].grade = 75;
	theClass[8].grade = 55;
	theClass[9].grade = 57;

	strcpy_s(theClass[0].name, "Russell");
	strcpy_s(theClass[1].name, "Tom");
	strcpy_s(theClass[2].name, "John");
	strcpy_s(theClass[3].name, "Sam");
	strcpy_s(theClass[4].name, "Paul");
	strcpy_s(theClass[5].name, "Mark");
	strcpy_s(theClass[6].name, "Lisa");
	strcpy_s(theClass[7].name, "Bailey");
	strcpy_s(theClass[8].name, "Sarah");
	strcpy_s(theClass[9].name, "Tina");
	
	theClass[0].id = 1005;
	theClass[1].id = 5672;
	theClass[2].id = 8372;
	theClass[3].id = 9275;
	theClass[4].id = 4444;
	theClass[5].id = 6719;
	theClass[6].id = 2367;
	theClass[7].id = 1025;
	theClass[8].id = 7890;
	theClass[9].id = 4242;

	theClass[0].bday = myDate(10, 2, 1992);
	theClass[1].bday = myDate(7, 16, 1992);
	theClass[2].bday = myDate(9, 27, 1992);
	theClass[3].bday = myDate(8, 12, 1992);
	theClass[4].bday = myDate(5, 9, 1992);
	theClass[5].bday = myDate(3, 24, 1992);
	theClass[6].bday = myDate(12, 25, 1992);
	theClass[7].bday = myDate(11, 18, 1992);
	theClass[8].bday = myDate(2, 19, 1992);
	theClass[9].bday = myDate(6, 1, 1992);

	for (k = 0; k < 10; k++)
	{
		byGrade[k] = &theClass[k];
		byName[k] = &theClass[k];
		byId[k] = &theClass[k];
		byBday[k] = &theClass[k];

		display(*byGrade[k]);

	}
	



	return 0;
}



void sortNames()
{
	return;
}