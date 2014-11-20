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
		char* MM_pool = new char[MM_POOL_SIZE];

		for (k = 0; k < MM_POOL_SIZE; k++)
		{
			MM_pool[k] = 'o';
		}
		MM_pool[0] = '0';
		MM_pool[1] = '6';
		MM_pool[2] = '0';
		MM_pool[3] = '0';
		MM_pool[4] = '`';
		MM_pool[5] = '~';
		for (k = 0; k < 600; k++)
		{
			if (k % 80 == 0)
			{
				std::cout << "\n";
			}
			std::cout << MM_pool[k];
		}
		std::cout<<freeRemaining();
	}
	void outOfMemory(void)
	{
		std::cerr << "Memory pool out of memory" << std::endl;
		exit(1);
	}
	void* allocate(int aSize)
	{

		int nextFree;
		int size;
		int dataSize;
		int count = 0;

		nextFree = 6 + aSize+(MM_POOL_SIZE-freeRemaining());

		MM_pool[MM_POOL_SIZE - freeRemaining() + 0] = (char)nextFree;
		MM_pool[MM_POOL_SIZE - freeRemaining() + count++] = (int)nextFree;
		MM_pool[MM_POOL_SIZE - freeRemaining() + count++] = (int)aSize % 16;
		MM_pool[MM_POOL_SIZE - freeRemaining() + count++] = (int)aSize % 8;
		for (int k = 0; k < aSize; k++)
		{
			MM_pool[MM_POOL_SIZE - freeRemaining() + count++] = 'x';
		}
		MM_pool[MM_POOL_SIZE - freeRemaining() + count++] = '`';
		MM_pool[MM_POOL_SIZE - freeRemaining() + count++] = '~';

		for (int k = 0; k < 600; k++)
		{
			if (k % 80 == 0)
			{
				std::cout << "\n";
			}
			std::cout << &MM_pool[k];
		}
				
		return new void*[aSize];
	}

	void deallocate(void* aPointer)
	{
		


	}

	int freeRemaining(void)
	{
		int k,count;
		k = 0;
		count = 0;

		for (k = 0; k < MM_POOL_SIZE; k++)
		{
			if (MM_pool[k] == (char)'o')
			{
				std::cout << "hit";
				count++;
			}
		}

		
		return MM_POOL_SIZE-count;
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