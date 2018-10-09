/***************************************************************************************
**	Program 1 - Example use of a CMutex object to enforce mutual exclusion
****************************************************************************************/
#include 	<stdio.h>		
#include 	"..\..\rt.h"					// change pathlist to "rt.h" to suit location on your disk


/* Part A:
 * 1.) All the C++ instructions are broken into assembly code. If the time slice occurs in between the read - add - write instruction then one process will pick the wrong value
 * 2.) Same idea, however moreso one program accessing the code while the other is modifying it.
 * 3.) Takes longer because of all the processor/kernel calls that must be made for the Mutex
 *
 */

struct 		mydatapooldata {			// data to be stored in a datapool
	unsigned long long int x;
};


int main()
{
	unsigned long long int a;

	//
	//	Start off with a datapool to represent our non-sharable resource. Now we need to make sure
	//	that only one process uses the datapool so we will need a mutex to protect it
	//

	CDataPool	dp1("MyDataPoolName", sizeof(struct mydatapooldata));		// create datapool
	struct 		mydatapooldata		*DataPtr = (struct mydatapooldata *)dp1.LinkDataPool();	// link to datapool

	CSemaphore S("MyMutex", 1); // Create Semaphore

	DataPtr->x = 0;

	CProcess p1(					// create a child process
		"..\\Debug\\Q8Child.exe",
		NORMAL_PRIORITY_CLASS,		// priority
		PARENT_WINDOW,					// process has it's own window
		ACTIVE						// process is active immediately
	);

	printf("Parent Process Updating Resource.....\n");

	for (unsigned long long int i = 0; i < 400000ULL; i++) 		// access resource note REDUCE SIZE OF LOOP WHEN USING MUTEX OTHERWISE IT TAKES FOREVER
	{
		S.Wait(); // Wait for access
		a = DataPtr->x;
		a = a + 1;
		DataPtr->x = a;	// update resource
		S.Signal(); // Relinquish access
	}


	p1.WaitForProcess();			// wait for child process to die

	printf("FINAL Value of x after PARENT AND CHILD PROCESS \nhave finished = %llu\n", DataPtr->x);
	getchar();
	return 0;
}
