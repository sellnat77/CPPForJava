#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

int main()
{
	multiset<int> mySet;
	multiset<int>::iterator walk;
	int k;
	int sum = 0;
	int rando;

	for (k = 0; k < 10000; k++)
	{
		rando = (int)((rand() %100)+1);
		mySet.insert(rando);
	}
	//mySet.sort();
	k = 0;
	for (walk = mySet.begin(); walk != mySet.end(); walk++)
	{
		if (k % 5 == 0 )
		{
			cout << "\n";
			k = 0;
		}
		printf("%3i",*walk);
		sum += *walk;
		k++;
	}
	cout << "\n";
	system("pause");

	cout << "\n\tSum = " << sum << "\n\n";
	system("pause");
	cout << "\n\tAverage = " << (int)(sum / 10000) << "\n\n";


	for (k = 0; k < 100; k++)
	{
		printf("Count of %3i = %3i",(k+1),mySet.count(k + 1));
		if (k % 5 == 0)
		{
			cout << "\n";
			
		}
	}
	

	return 0;
}