#include <iostream>
#include "..\..\rt.h"
#include "MonitorVariable.h"

// Authors:
// Alex Von Schulmann 13975140
// Alec Xu            38108130
 /*
 
 Better because if you are using a Monitor, whoever designed the data that needed to protected it is the one to protect it. Not the person implementing that data in some 'main'
 
 */

MonitorVariable	x("x"); // Make monitor variable 'x'

UINT    __stdcall   secondThread(void *args)	
{
	for (int i = 0; i < 100000; i++) {
		x.increment();
	}
	return 0;
}

void main()
{
	x.write(1000);									// Start at 1000
	CThread myThread(secondThread, ACTIVE, NULL);

	for (int i = 0; i < 100000; i++) {
		x.increment();								// Add 100 000 from main (and 100 000 from second thread)
	}
	myThread.WaitForThread();
	printf("%d\n", x.read());						// Should read 201 000
}
