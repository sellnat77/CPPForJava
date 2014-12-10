/* Russell Tan
 * 011529945
 * C++ For Java Programmers
 * Professor Gold
 * 12/09/2014
 */

#include <iostream>
#include <time.h>
#include <set>

using namespace std;

int main()
{
	srand(time(NULL));
	multiset<int> mySet;
	multiset<int>::iterator walk;
	
	int sum = 0;
	int k = 0;
	int rando;

	for (k = 0; k < 10000; k++)
	{
		mySet.insert((int)((rand() % 100) + 1));
	}
	
	for (walk = mySet.begin(); walk != mySet.end(); walk++)
	{
		if (k % 25 == 0 )
		{
			cout << "\n";
			k = 0;
		}

		printf("%3i",*walk);
		sum += *walk;
		k++;
	}

	cout << "\n\n\tSum = " << sum << "\n\n";
	system("pause");
	printf("\n\tAverage = %3.2f\n\n", ((1.0*sum) / 10000));
	
	for (k = 0; k < 100; k++)
	{
		printf("%3i: %3i ",(k+1),mySet.count(k + 1));
		
		if ((k+1) % 5 == 0 )
		{
			cout << "\n\n";	
		}
	}

	cout << "\n\n";
	return 0;
}