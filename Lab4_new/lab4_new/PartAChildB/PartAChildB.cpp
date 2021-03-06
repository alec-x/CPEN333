#include 	<stdio.h>
#include 	"..\..\rt.h"	

struct 	    mydatapooldata {		// start of structure template
	char nameA[32];
	char nameB[32];
	int age[2];
	int birthYear[2];
};

int   main()
{
	int i;

	printf("Child attempting to create/use the datapool.....\n");
	CDataPool 		dp("OurInfo", sizeof(struct mydatapooldata));

	struct mydatapooldata 	 *MyDataPool = (struct mydatapooldata *)(dp.LinkDataPool());

	printf("Child linked to datapool at address %p.....\n", MyDataPool);

	// Print out our data
	printf("Child Read value for first name = %s\n", MyDataPool->nameA);
	printf("Child Read value for first age = %d\n", MyDataPool->age[0]);
	printf("Child Read value for first birth year = %d\n", MyDataPool->birthYear[0]);

	getchar();

	return 0;
}