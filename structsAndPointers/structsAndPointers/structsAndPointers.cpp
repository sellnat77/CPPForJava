#include "myDate.h"
#include <string>

struct Student
{
	int grade;
	char name[10];
	int id;
	myDate bday;

};

void dislplayList()
{
	cout << "1) Display original list\n";
	cout << "2) Display list sorted by ID\n";
	cout << "3) Display list sorted by age, oldest to youngest\n";
	cout << "4) Display list sorted alpabetically by name\n";
	cout << "5) Display list sorted by grade\n";
	cout << "6) Exit\n\n";
}

void display(Student var)
{
	cout << "Name: " << var.name << "\t\t";
	cout << "Grade   : " << var.grade << "\n";
	
	cout << "ID  : " << var.id << "\t\t";
	cout << "Birthday: ";
	var.bday.display();
	cout << "\n\n";
}

void sortNames(Student students[])
{
	int j, k;
	Student temp;

	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{
			if (strcmp(students[j].name,students[k].name) < 0)
			{
				temp = students[j];
				students[j] = students[k];
				students[k] = temp;
			}
		}
	}


}

void sortIds(Student students[])
{
	int j, k;
	Student temp;

	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{
			if (students[j].id < students[k].id)
			{
				temp = students[j];
				students[j] = students[k];
				students[k] = temp;
			}
		}
	}

}

void sortBirthdays(Student students[])
{
	int j, k;
	Student temp;

	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{
			myDate bday1 = students[j].bday;
			myDate bday2 = students[k].bday;
			if (students[j].bday.gregToJulian(bday1) < students[k].bday.gregToJulian(bday2))
			{
				temp = students[j];
				students[j] = students[k];
				students[k] = temp;
			}
		}
	}

}

void sortGrades(Student students[])
{
	int j, k;
	Student temp;

	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{
			if (students[j].grade < students[k].grade)
			{
				temp = students[j];
				students[j] = students[k];
				students[k] = temp;
			}
		}
	}

}


int main()
{
	Student theClass[10];
	Student *byGrade[10];
	Student *byName[10];
	Student *byId[10];
	Student *byBday[10];
	bool again = false;
	int choice = 0;
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
	theClass[1].bday = myDate(7, 16, 1994);
	theClass[2].bday = myDate(9, 27, 1997);
	theClass[3].bday = myDate(8, 12, 1998);
	theClass[4].bday = myDate(5, 9, 2005);
	theClass[5].bday = myDate(3, 24, 2000);
	theClass[6].bday = myDate(12, 25, 2008);
	theClass[7].bday = myDate(11, 18, 2012);
	theClass[8].bday = myDate(2, 19, 2014);
	theClass[9].bday = myDate(6, 1, 2013);

	for (k = 0; k < 10; k++)
	{
		byGrade[k] = &theClass[k];
		byName[k] = &theClass[k];
		byId[k] = &theClass[k];
		byBday[k] = &theClass[k];
	}


	
	while (!again)
	{
		dislplayList();
		cout << "What would you like to do? ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			for (k = 0; k < 10; k++)
			{
				display(theClass[k]);
			}
			break;
		case 2:
			cout << "By Id";
			sortIds(*byId);
			for (k = 0; k < 10; k++)
			{
				display(*byId[k]);
			}
			break;
		case 3:
			cout << "By birthday\n";
			sortBirthdays(*byBday);
			for (k = 0; k < 10; k++)
			{
				display(*byBday[k]);
			}
			break;
		case 4:
			cout << "By name\n";
			sortNames(*byName);
			for (k = 0; k < 10; k++)
			{
				display(*byName[k]);
			}
			break;
		case 5:
			cout << "By grade\n";
			sortGrades(*byGrade);

			for (k = 0; k < 10; k++)
			{
				display(*byGrade[k]);
			}
			break;
		default:
			again = true;
			break;
		}

	}
	
	



	return 0;
}
