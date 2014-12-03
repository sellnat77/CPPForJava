#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

#include "MemoryManager.h"

int main(void)
{
	using namespace MemoryManager;

	std::cout << "Initialize uses 6 bytes...expecting 65530\n";
	initializeMemoryManager();
	
	long* int_pointer;
	char* string_pointer;

	std::cout << "Free memory = " << freeRemaining() << "\n\n";
	//std::cout << sizeof(long);
	
	std::cout << "Allocating size 4 plus additional 6 bytes...expecting 65520\n";
	int_pointer = (long*)allocate(sizeof(long)); //4
	
	std::cout << "Free memory = " << freeRemaining() << "\n\n";
	
	std::cout << "Allocating size 20 plus additional 6 bytes...expecting 65494\n";
	string_pointer = (char*)allocate(20); //255
	//std::cout << "size of string pointer" << sizeof(string_pointer);

	//std::cout << "Free memory = " << freeRemaining() << "\n\n";
	
	//*int_pointer = 0xDEADBEEF;//too big

	//std::cout << "Free memory = " << freeRemaining() << std::endl;

	//strcpy(string_pointer, "It was the best of times, it was the worst of times"); //fine
	//std::cout << "size of string pointer" << string_pointer[0] << string_pointer[1] << string_pointer[2];

	std::cout << "Free memory = " << freeRemaining() << "\n\n";
	
	std::cout << "Deallocating size 4 plus 6 bytes...expecting 65504\n";
	deallocate(int_pointer);
	std::cout << "Free memory = " << freeRemaining() << "\n\n";
	
	std::cout << "Deallocating size 20 plus 6 bytes...expecting 65530\n";
	deallocate(string_pointer);
	std::cout << "Free memory = " << freeRemaining() << "\n\n";
	

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