#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

int main()
{
	list<int> mySet;
	list<int>::iterator walk;
	int k;
	int sum = 0;
	int rando;

	for (k = 0; k < 10000; k++)
	{
		rando = (int)((rand() %100)+1);
		mySet.push_front(rando);
	}
	mySet.sort();
	k = 0;
	for (walk = mySet.begin(); walk != mySet.end(); walk++)
	{
		if (k == 19 )
		{
			//cout << "\n";
			k = 0;
		}
		printf("%1i",*walk);
		sum += *walk;
		k++;
	}
	cout << "\n";
	system("pause");

	cout << "\n\tSum = " << sum << "\n\n";
	system("pause");
	cout << "\n\tAverage = " << (int)(sum / 10000) << "\n\n";

	

	return 0;
}