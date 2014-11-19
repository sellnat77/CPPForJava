#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

#include "MemoryManager.h"

namespace MemoryManager
{
	const int MM_POOL_SIZE = 65536;
	char MM_pool[MM_POOL_SIZE];

	void initializeMemoryManager(void)
	{
		int k;
		char* MM_pool;

		MM_pool = new char[MM_POOL_SIZE];

		for (k = 0; k < MM_POOL_SIZE; k++)
		{
			MM_pool[k] = 'o';
		}


	}
	void outOfMemory(void)
	{
		std::cerr << "Memory pool out of memory" << std::endl;
		exit(1);
	}
	void* allocate(int aSize)
	{
		int k,temp;

		std::cout << "aSize=  " << aSize << "\tFree = " << freeRemaining() <<"\n";
		if (aSize > freeRemaining() || aSize < 0)
		{
			outOfMemory();
		}
		for (k = MM_POOL_SIZE-freeRemaining(); k < aSize; k++)
		{
			MM_pool[k] = 'x';			
		}			
		return new void*[aSize];
	}

	void deallocate(void* aPointer)
	{
		int k,count;
		count = 0;
		char* temp = (char*)aPointer;

		for (k = MM_POOL_SIZE-freeRemaining()-sizeof(temp); k < sizeof(temp); k++)
		{
			if (MM_pool[k] == 'x')
			{
				count++;
				MM_pool[k] = 'o';
			}
		}


		delete[] temp;
		temp = NULL;
	}

	int freeRemaining(void)
	{
		int k,count;
		k = 0;
		count = MM_POOL_SIZE;

		while (k < MM_POOL_SIZE)
		{

			if (MM_pool[k] == 'x')
			{
				count--;
			}
			k++;
		}
		return count;
	}

	int largestFree()
	{
		return 0;
	}

	int smallestFree(void)
	{
		return 0;
	}



	//Call if a pointer is over run condition is detected
	void onOverrunDetected(void)
	{
		std::cerr << "Pointer overrun detected" << std::endl;
		exit(1);
	}

	//Call for any other error condition, providing meaningul error messages are appreciated
	void onIllegalOperation(const char* fmt)
	{
		if (fmt == NULL)
		{
			std::cerr << "Unknown illegal operation" << std::endl;
			exit(1);
		}
		else
		{
			char buf[8192];

			va_list argptr;
			va_start(argptr, fmt);
			vsprintf(buf, fmt, argptr);
			va_end(argptr);

			std::cerr << "Illegal operation: \"" << buf << "\"" << std::endl;
		}
	}
}