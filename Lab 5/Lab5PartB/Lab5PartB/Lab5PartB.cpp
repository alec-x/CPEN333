#include <iostream>
#include "..\..\rt.h"
// Authors:
// Alex Von Schulmann 13975140
// Alec Xu            38108130
/* Part B:
 * Problem witnessed: being printed to the incorrect location (because one of them will call move cursor then the other prints)
 * Solution: make the act of moving the cursor to a location and printing an uninterruptable sequence using semaphores
 */

UINT __stdcall SecondThread(void *args)
{
	CSemaphore S("MyMutex", 1);
	for (int i = 0; i < 1000; i++)
	{
		S.Wait();
		MOVE_CURSOR(20, 20);
		printf("Hello from Thread 2\n");
		fflush(stdout);
		S.Signal();
	}

	return 0;
}

int main() {
	
	CSemaphore S("MyMutex", 1);
	CThread* myThread = new CThread(SecondThread, ACTIVE);
	for (int i = 0; i < 1000; i++)
	{
		S.Wait();
		MOVE_CURSOR(10, 10); 
		printf("Hello from Thread 1\n");
		fflush(stdout);
		S.Signal();
	}
	myThread->WaitForThread();
	delete(myThread);

	return 0;
}