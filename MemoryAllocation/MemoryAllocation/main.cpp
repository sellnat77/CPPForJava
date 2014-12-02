#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

#include "MemoryManager.h"

int main(void)
{
	using namespace MemoryManager;

	initializeMemoryManager();
	
	long* int_pointer;
	char* string_pointer;

	//std::cout << "Free memory = " << freeRemaining() << std::endl;
	//std::cout << sizeof(long);
	
	//int_pointer = (long*)allocate(sizeof(long)); //4

	std::cout << "Free memory = " << freeRemaining() << std::endl;
	
	//string_pointer = (char*)allocate(255); //255

	std::cout << "Free memory = " << freeRemaining() << std::endl;
	/*
	*int_pointer = 0xDEADBEEF;//too big

	std::cout << "Free memory = " << freeRemaining() << std::endl;

	strcpy(string_pointer, "It was the best of times, it was the worst of times"); //fine

	std::cout << "Free memory = " << freeRemaining() << std::endl;

	deallocate(int_pointer);
	std::cout << "Free memory = " << freeRemaining() << std::endl;

	deallocate(string_pointer);
	std::cout << "Free memory = " << freeRemaining() << std::endl;
	*/

}
/*
namespace MemoryManager
{
	void outOfMemory(void)
	{
		std::cerr << "Memory pool out of memory" << std::endl;
		exit(1);
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
*/