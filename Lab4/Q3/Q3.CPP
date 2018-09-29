#include 	<stdio.h>
#include 	"..\rt.h"		// change pathlist to "rt.h" file to suit location on disk

// Let's suppose the data we want to put in the datapool is complex, i.e not just a simple
// int or char. The easiest way to store complex data is to introduce a structure template
// describing the names and types of the data we wich to group together as shown below
//  which includes three variables, two simple integers and an array of 10 integers
  
struct 	    mydatapooldata 	{		// start of structure template
		char nameA[32];				// === CAN'T USE STRINGS BECAUSE NEED TO KNOW SIZE ===
		char nameB[32];
		int age[2] ;			
		int birthYear[2] ;
} ;							

int 	main()
{
//	Start by making a datapool called 'Car1'. This is actual name of the global datapool
//	we are creating, which can then be shared by all other processes in the system
//	Note that we do not have to worry about which of the many processes using the datapool will
//	actually make it, because when a request is made to make a datapool, the operating system 
//	checks to see if it exists or not. If not, then the pool will be made, otherwise the process
//	will simply 'use' the pool if it finds it already exists.
//
//	Note we also have to specify the size of the datapool we are making and because we want it
//	to hold the data in the structure template above, we make it that big

	printf("Parent attempting to create/use the datapool.....\n") ;
	CDataPool 		dp("OurInfo", sizeof(struct mydatapooldata)) ;
	
// In order to access the data pool, we need a pointer to its location in memory. This is what
// the LinkDataPool() primitive does. It gives us back a pointer to the data pool referred to by 'dp'.
// Note that because the operating system doesn't know the purpose of our datapool, i.e. what data
// we are going to put in it, we have to 'cast' or 'convert' the actual pointer returned into a pointer
// to the data we want to store inside the datapool, i.e. convert it to a pointer to the structure
// mydatapooldata. Hence the pointer MyDataPool below is a pointer to a structure that we
// want to map onto the datapool
	
	
//	struct mydatapooldata 	 *MyDataPool = (struct mydatapooldata *)(0x1000) ;    // just to show an error

	struct mydatapooldata 	 *MyDataPool = (struct mydatapooldata *)(dp.LinkDataPool()) ;

	printf("Parent linked to datapool at address %p.....\n", MyDataPool) ;

// Now that we have the pointer to the datapool, we can put data into it

	printf("Parent Writing value 'Alex' to nameA and 'Alec' to nameB.....\n") ;
	strcpy(MyDataPool->nameA, "Alex");
	strcpy(MyDataPool->nameB, "Alec");

	printf("Parent Writing value '22' to age[0] and '23(?)' to age[1].....\n") ;
	MyDataPool->age[0] = 22;
	MyDataPool->age[1] = 23;

	printf("Parent Writing value '1996' to birthYear[0] and '1995' to birthYear[1].....\n") ;
	MyDataPool->birthYear[0] = 1996;
	MyDataPool->birthYear[1] = 1995;

	printf("Enter to create child process.....\n");


//	Now that we have created the data pool and have stored data in it, it is safe to create
//	a child process that can access the data

	getchar() ;

	CProcess p1("C:\\Users\\alexv\\Documents\\Source\\Repos\\CPEN333\\Lab4\\Q3\\Q4\\debug\\Q4.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window
		ACTIVE							// process is active immediately
	) ;

	CProcess p2("C:\\Users\\alexv\\Documents\\Source\\Repos\\CPEN333\\Lab4\\Q3\\debug\\Q4b.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window
		ACTIVE							// process is active immediately
	);

	p1.WaitForProcess();		// wait for the child process to Terminate
	p2.WaitForProcess();		// wait for the child process to Terminate

	return 0 ;				// CDataPool object 'dp' destroyed here
}