#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

#include "MemoryManager.h"

namespace MemoryManager
{
	const int MM_POOL_SIZE = 65;
	char* MM_pool = new char[MM_POOL_SIZE];

	void initializeMemoryManager(void)
	{
		int k;
		//char* pool = new char[MM_POOL_SIZE];
		for (k = 0; k < MM_POOL_SIZE; k++)
		{
			MM_pool[k] = NULL;
			std::cout << (unsigned short)MM_pool[k];
		}
		*(unsigned short*)(void*)(MM_pool + 0) = 6;//Total used
		*(unsigned short*)(void*)(MM_pool + 1) = 6;//Next free
		*(unsigned short*)(void*)(MM_pool + 2) = 0;//Prev free
		std::cout << "size = " << sizeof((unsigned short)MM_pool[1]) << "\t\t";
		std::cout << "size = " << (unsigned short)MM_pool[1] << "\t\t";
		for (k = 0; k < MM_POOL_SIZE; k++)
		{
			std::cout << (unsigned short)MM_pool[k];
		}
		*(unsigned short*)(void*)(MM_pool + 3) = 10;//Total used
		*(unsigned short*)(void*)(MM_pool + 4) = 16;//Next free
		*(unsigned short*)(void*)(MM_pool + 5) = 5;//Prev free
		*(unsigned short*)(void*)(MM_pool + 8) = 8;//Total used
		*(unsigned short*)(void*)(MM_pool + 9) = 24;//Next free       
		*(unsigned short*)(void*)(MM_pool + 10) = 11;//Prev free
		*(unsigned short*)(void*)(MM_pool + 13) = 9;//Total used
		*(unsigned short*)(void*)(MM_pool + 14) = 33;//Next free
		*(unsigned short*)(void*)(MM_pool + 15) = 21;//Prev free
		*(unsigned short*)(void*)(MM_pool + 17) = 10;//Total used
		*(unsigned short*)(void*)(MM_pool + 18) = 43;//Next free       
		*(unsigned short*)(void*)(MM_pool + 19) = 30;//Prev free
		for (k = 0; k < MM_POOL_SIZE; k++)
		{
			std::cout << (unsigned short)MM_pool[k];
		}
		std::cout << "Value of 6 = " << (unsigned short)MM_pool[1];
		
	}
	void outOfMemory(void)
	{
		std::cerr << "Memory pool out of memory" << std::endl;
		exit(1);
	}
	void* allocate(int aSize)
	{

		return NULL;
	}

	void deallocate(void* aPointer)
	{
		


	}

	int freeRemaining(void)
	{
		int position;
		unsigned short used = (unsigned short)MM_pool[0];
		unsigned short next = (unsigned short)MM_pool[1];
		unsigned short prev = (unsigned short)MM_pool[2];
		unsigned short count = 0;
		int k = 0;

		std::cout << "\n\n\n\t\tValue of 6 = " << next << "\n\n\n\n";

		for (k = 0; k < MM_POOL_SIZE; k++)
		{
			std::cout << (unsigned short)MM_pool[k];
			
		}
		k = 0;

		std::cout << "K = " << k;

		while (k < MM_POOL_SIZE)
		{
			std::cout << "COUNT: " << count;
			k += (int)next;
			count += used;
			used = (unsigned short)MM_pool[count / 2];
			next = (unsigned short)MM_pool[(count / 2) + 1];
			prev = (unsigned short)MM_pool[(count / 2) + 2];
			std::cout << "COUNT: " << count;
			if (used == 0)
			{
				break;
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