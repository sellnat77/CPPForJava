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
			//std::cout << *(unsigned short*)MM_pool+k;
		}

		//*(unsigned short*)(void*)(MM_pool + 0) = 261;//Total used
		

		*(unsigned short*)(void*)(MM_pool + 0) = 6;//Total used	
		*(unsigned short*)(void*)(MM_pool + 1) = 6;//Next free
		*(unsigned short*)(void*)(MM_pool + 2) = 0;//Prev free

		//std::cout << "Value of 6 = " << (unsigned short)(MM_pool[0]) << "\n";
		/*
		*(unsigned short*)(void*)(MM_pool + 3) = 10;//Total used
		*(unsigned short*)(void*)(MM_pool + 4) = 16;//Next free
		*(unsigned short*)(void*)(MM_pool + 5) = 5;//Prev free
		*/
		/*
		*(unsigned short*)(void*)(MM_pool + 8) = 10;//Total used
		*(unsigned short*)(void*)(MM_pool + 9) = 26;//Next free       
		*(unsigned short*)(void*)(MM_pool + 10) = 11;//Prev free

		*(unsigned short*)(void*)(MM_pool + 13) = 14;//Total used
		*(unsigned short*)(void*)(MM_pool + 14) = 40;//Next free       
		*(unsigned short*)(void*)(MM_pool + 15) = 21;//Prev free
		*/
		
		//for (k = 0; k < 11; k++)
		//{
		//	std::cout << "MM_pool[" << k << "] = " << (unsigned short)(MM_pool[k]) << "\n";
		//}
		//std::cout << "Value of 6 = " << (unsigned short)(MM_pool[0]);
		
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

		//nextOpen += (unsigned short)((int)(1.0*(abs(MM_POOL_SIZE - freeRemaining())))+(aSize-6));
		nextOpen += abs(freeRemaining()-MM_POOL_SIZE);
		std::cout << "Next available spot" << nextOpen << "\n\n";
		totalUsed = (unsigned short)(aSize + 6);
		//std::cout << "USING " << (unsigned short)totalUsed << "\n\n\n";
		//std::cout << "Being stored at " << nextOpen;
		nextFree = (unsigned short)(totalUsed+(abs(MM_POOL_SIZE - freeRemaining())));
		prevFree = (unsigned short)((abs(MM_POOL_SIZE - freeRemaining()) - 1));

		*(unsigned short*)(void*)(MM_pool+nextOpen) = totalUsed;
		temp = *(unsigned short*)(MM_pool + nextOpen);
		//std::cout << "\n\n\n\n\t" << temp;
		*(unsigned short*)(void*)(MM_pool + nextOpen+1) = nextFree;
		*(unsigned short*)(void*)(MM_pool + nextOpen+2) = prevFree;
		startOfAllocated = (MM_pool + nextOpen + 3);

		
		//std::cout << "MMPool[" << 8 << "] = " << temp << "\n";


		/*

		totalUsed = (unsigned short)(aSize+6);
		nextOpen = totalUsed / 2;
		std::cout << "\nValue of 10 = " << totalUsed << "\n\n";
		nextFree = (unsigned short)((MM_POOL_SIZE - freeRemaining()) + totalUsed);
		std::cout << "\nValue of 16 = " << nextFree << "\n\n";
		prevFree = (unsigned short)(MM_POOL_SIZE - freeRemaining()-1);
		std::cout << "\nValue of 5 = " << prevFree << "\n\n";


		std::cout << "\nnext open = " << nextOpen<<"\n\n";
		*(unsigned short*)(void*)(MM_pool + nextOpen) = totalUsed;
		*(unsigned short*)(void*)(MM_pool + (nextOpen + 1)) = nextFree;
		*(unsigned short*)(void*)(MM_pool + (nextOpen + 2)) = prevFree;
		std::cout << "\n\nvalue of 10 = " << (unsigned short)(MM_pool[(nextOpen+0)]) << "\n\n";
		std::cout << "\n\nvalue of 16 = " << (unsigned short)(MM_pool[nextOpen+1]) << "\n\n";
		std::cout << "\n\nvalue of 5 = " << (unsigned short)(MM_pool[nextOpen+2]) << "\n\n";
		startOfAllocated = (void*)(MM_pool +( nextOpen + 3));

		for (k = 0; k < 5000; k++)
		{
			if (k % 3 == 0)
			{
				std::cout << "\n";
			}
			if ((unsigned short)(MM_pool[k]) == totalUsed)
			{
				std::cout << "MM_pool[" << k << "] = " << (unsigned short)(MM_pool[k]) << "\t";
				break;
			}
			std::cout << "MM_pool[" << k << "] = " << (unsigned short)(MM_pool[k]) << "\t";
		}


		*/

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
			//std::cout << "count is " << count << "\n\n";
		}
		std::cout << "count is " << count << "\n\n";

	}

	int freeRemaining(void)
	{
		int position = 0;
		int k = 0;
		unsigned short used = (unsigned short)(MM_pool[position]);
		//std::cout << "\nUSED = " << used;
		unsigned short next = (unsigned short)(MM_pool[position+1]);
		unsigned short prev = (unsigned short)(MM_pool[position+2]);
		unsigned short count = used;
		//std::cout << "\n\nStart counting\n";
		//std::cout << "\nK: " << k;
		//std::cout << "\nUSE 6: " << used; 
		//std::cout << "\nCOUNT: " << count;
		//std::cout << "\nCOUNT/2: " << (int)((1.0*count) / 2);
		//std::cout << "\nNext: " << next;

		//for (k = 0; k < MM_POOL_SIZE / 500; k++)
		//{
		//	std::cout << (unsigned short)(MM_pool[k]);
		//}
		
		k = used;

		while (k < MM_POOL_SIZE)
		{
			position = (int)(ceil((1.0*next) / 2));
			/*
			std::cout << "\nK: " << k;
			std::cout << "\nUSE BEFORE: " << used;
			std::cout << "\nCOUNT: " << count;
			std::cout << "\nCOUNT/2: " << count/2;
			std::cout << "\nNext: " << next;
			*/
			k += next;
			count += used;
			//std::cout << "\nCOUNT: " << count;

			used = (unsigned short)MM_pool[position];
			
			next = (unsigned short)MM_pool[position + 1];
			
			//std::cout << "\nK: " << k;
			//std::cout << "\nUSE AFTER: " << used;
			if (used == (unsigned short)((char)('o')))
			{
				count -= 6;
				break;
			}			
			
		}
		//std::cout << "Used = " << abs(MM_POOL_SIZE-MM_POOL_SIZE-count) << "\n";
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

	void print()
	{
		int k; 

		for (k = 0; k < 500; k++)
		{
			if (k % 5 == 0)
			{
				std::cout << "\n";
			}
			std::cout << "[" << k << "] = " << (unsigned short)(MM_pool[k]);
		}
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