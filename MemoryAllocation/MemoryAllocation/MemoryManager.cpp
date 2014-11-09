#include "MemoryManager.h"
namespace MemoryManager
{
	const int MM_POOL_SIZE = 65536;
	char MM_pool[MM_POOL_SIZE];
	void initializeMemoryManager(void)
	{

	}

	void* allocate(int aSize)
	{
		return ((void*)0);
	}

	void deallocate(void* aPointer)
	{
		
	}

	int freeRemaining(void)
	{
		return 0;
	}

	int largestFree()
	{
		return 0;
	}

	int smallestFree(void)
	{
		return 0;
	}

	void onOutMemory(void)
	{

	}
}