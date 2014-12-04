

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

#include "MemoryManager.h"

int main(void)
{
	using namespace MemoryManager;

	initializeMemoryManager();

	int a;
	//long* int_pointer;
	//char* string_pointer;
	/*

	std::cout << "Free memory = " << freeRemaining() << std::endl;

	int_pointer = (long *)allocate(sizeof(long));
	std::cout << "Mem Address:" << (long)int_pointer << std::endl;
	std::cout << "Free memory = " << freeRemaining() << std::endl;
	std::cout << "Largest Free Memory Block = " << largestFree() << std::endl;

	string_pointer = (char*)allocate(255);

	std::cout << "Mem Address:" << (long)string_pointer << std::endl;
	std::cout << "checkpoint 1\n";
	//std::cin>>a;

	*int_pointer = 0xDEADBEEF0;
	std::cout << string_pointer;

	std::cout << "Free memory = " << freeRemaining() << std::endl;
	std::cout << "Largest Free Memory Block = " << largestFree() << std::endl;
	std::cout << "checkpoint 2\n";
	//std::cin>>a;

	strcpy(string_pointer, "It was the best of times, it was the worst of times");
	std::cout << string_pointer;

	std::cout << "checkpoint 3\n";
	std::cout << "Free memory = " << freeRemaining() << std::endl;
	std::cout << "Largest Free Memory Block = " << largestFree() << std::endl;
	*/
	// the next several lines are the new lines that I have added for testing
	int *iptr[20];
	int i;
	std::cout << "Prior to allocation free mem = " << freeRemaining() << "\n";
	// 10 points if this part of the program works - this for loop
	for (i = 1; i<20; i++)
	{
		iptr[i] = (int *)allocate(sizeof(int));
		std::cout << "Allocation #" << i << " Size = " << (sizeof(int)) << " Free mem = " << freeRemaining() << std::endl;
	}
	print();
	/*
	// 10 points if this part of the program works - this for look
	for (i = 1; i<20; i++)
	{
		//deallocate(iptr[i]);
		std::cout << "Deallocation #" << i << "Free mem = " << freeRemaining() << std::endl;
	}
	*/
	//deallocate(int_pointer);
	//deallocate(string_pointer);

	//std::cin >> a;
}
/*
namespace MemoryManager
{
	void onOutOfMemory(void)
	{
		std::cerr << "Memory pool out of memory" << std::endl;
		exit(1);
	}

	// Call if a pointer over run condition is detected
	void onOverrunDetected(void)
	{
		std::cerr << "Pointer overrun detected" << std::endl;
		exit(1);
	}

	// call for any other error condition, providing meaningful error messages are appreciated
	void onIllegalOperation(const char* fmt, ...)
	{
		if (fmt == NULL)
		{
			std::cerr << "Unknown illegal operation" << std::endl;
			exit(1);
		}
		else
		{
			char	buf[8192];

			va_list argptr;
			va_start(argptr, fmt);
			vsprintf(buf, fmt, argptr);
			va_end(argptr);

			std::cerr << "Illegal operation: \"" << buf << "\"" << std::endl;
			exit(1);
		}
	}
}
*/