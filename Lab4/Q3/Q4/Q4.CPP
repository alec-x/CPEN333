// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	This example Pocess makes/uses a datapool and reads data out
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include 	<stdio.h>
#include 	"..\\..\rt.h"		// change pathlist to "rt.h" file to suit location on disk

//
//	It's important to realise that all processes accessing the same datapool must
//	describe exactly the same datapool or structure template otherwise corruption
//	of data will occur. Ideally, the structure template would be put into a single header file
//	which would be '#include'd' into each program that used that datapool. However, for
//	simplicity, we have recreated the same template in each process
//
  
struct 	    mydatapooldata {		// start of structure template
	char nameA[32];
	char nameB[32];
	int age[2];
	int birthYear[2];
};

int   main()
{
	int i ;

// 	Attempt to make the datapool 'Car1'. This process will not know
//	whether the datapool exists or not yet (we know that it does because we only
//	set the process running after the parent program had created it and stored data
//	in it) but that shouldn't matter, since the program can just attempt to make it. If it already exists
//	then it will simply use it. If it doesn't exist, then it will be created below


	printf("Child attempting to create/use the datapool.....\n") ;
	CDataPool 		dp("OurInfo", sizeof(struct mydatapooldata)) ;
	
// In order to access the data pool, we need a pointer to its location in memory. This is what
// the LinkDataPool() primitive does as we saw in the parent program
	
//	struct mydatapooldata 	 *MyDataPool = (struct mydatapooldata *)(0x1000) ;    // just to show an error

	struct mydatapooldata 	 *MyDataPool = (struct mydatapooldata *)(dp.LinkDataPool()) ;

	printf("Child linked to datapool at address %p.....\n", MyDataPool) ;

// print out the data in the datapool that was stored there by the parent

	printf("Child Read value for second name = %s\n", MyDataPool->nameB);
	printf("Child Read value for second age = %d\n", MyDataPool->age[1]);
	printf("Child Read value for second birth year = %d\n", MyDataPool->birthYear[1]);

// The CDatapool object 'dp' created at the start of the program will now be destroyed
// and provided there are no other processes using the same named datapool, then that datapool
// will also be destroyed
	
	getchar();			// pause seconds so programmer can view output before child dies

	return 0 ;
}