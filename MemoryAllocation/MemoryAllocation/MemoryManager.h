#pragma once

#ifndef _MEMORYMANAGER_H
#define _MEMORYMANAGER_H
namespace MemoryManager
{
	void initializeMemoryManager(void);

	void* allocate(int aSize);

	void deallocate(void* aPointer);

	int freeRemaining(void);

	int largestFree();

	int smallestFree(void);

	void onOutMemory(void);
	void onOverrunDetected(void);


};
#endif