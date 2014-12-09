#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

#include "MemoryManager.h"

namespace MemoryManager
{
	const int MM_POOL_SIZE = 65536; //65536
	char* MM_pool = new char[MM_POOL_SIZE];

	void initializeMemoryManager(void)
	{
		int k;
		//char* MM_pool = new char[MM_POOL_SIZE];
		for (k = 0; k < MM_POOL_SIZE; k++)
		{
			MM_pool[k] = 'o';
		}

		

		*(unsigned short*)(void*)(MM_pool + 0) = 6;//Total used	
		*(unsigned short*)(void*)(MM_pool + 1) = 6;//Next free
		*(unsigned short*)(void*)(MM_pool + 2) = 0;//Prev free
		
	}
	void outOfMemory(void)
	{
		std::cerr << "Memory pool out of memory" << std::endl;
		exit(1);
	}
	void* allocate(int aSize)
	{
		void* startOfAllocated = NULL;
		unsigned short totalUsed;
		unsigned short nextFree;
		unsigned short prevFree;
		static int nextOpen;
		
		unsigned short temp;
		int k;

		nextOpen += ((int)(1.0*(abs(MM_POOL_SIZE - freeRemaining())) / 2));
		std::cout << "Next available spot" << nextOpen << "\n\n";
		totalUsed = (unsigned short)(aSize + 6);

		nextFree = (unsigned short)(totalUsed+(abs(MM_POOL_SIZE - freeRemaining())));
		prevFree = (unsigned short)((abs(MM_POOL_SIZE - freeRemaining()) - 1));

		*(unsigned short*)(void*)(MM_pool+nextOpen) = totalUsed;
		temp = *(unsigned short*)(MM_pool + nextOpen);
		*(unsigned short*)(void*)(MM_pool + nextOpen+1) = nextFree;
		*(unsigned short*)(void*)(MM_pool + nextOpen+2) = prevFree;
		startOfAllocated = (MM_pool + nextOpen + 3);

		return startOfAllocated;
	}

	void deallocate(void* aPointer)
	{
		int k=0;
		unsigned short count = 0;
		char* point = (char*)aPointer;

		while (k < MM_POOL_SIZE)
		{
			
			count++;
			k++;
		}
		std::cout << "count is " << count << "\n\n";

	}

	int freeRemaining(void)
	{
		int position = 0;
		int k = 0;
		unsigned short used = (unsigned short)(MM_pool[position]);
		unsigned short next = (unsigned short)(MM_pool[position+1]);
		unsigned short prev = (unsigned short)(MM_pool[position+2]);
		unsigned short count = used;

		
		k = used;

		while (k < MM_POOL_SIZE)
		{
			position = (int)(ceil((1.0*next) / 2));

			k += next;
			count += used;


			used = (unsigned short)MM_pool[position];
			
			next = (unsigned short)MM_pool[position + 1];

			if (used == (unsigned short)((char)('o')))
			{
				count -= 6;
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