#include "C:\Repos\CPEN333\RTExamples\rt.h"
#include <iostream>
// Author: Alec Xu 38108130
// Author: Alex von Schulmann 13975140

UINT __stdcall ChildThread(void *args)	// A thread function 
{
	string myArgument = *(string *)(args);

	printf("I am the Child thread: My argument is: \n");
	printf("%s\n", myArgument);

	return 0;
}

int 	main()
{
	printf("Parent Thread: Creating Child Thread\n");
	printf("Parent Thread: passing in string = CPEN333 is Awesome \n");
	string testString = "CPEN333 is Awesome";
	CThread* testThread = new CThread(ChildThread, ACTIVE, &testString);

	printf("Parent Thread: Waiting for Child thread to return \n");
	testThread->WaitForThread();
	delete testThread;	// delete the object created by ‘new’
	printf("Parent Thread: Deleted Child thread \n");
	return 0;
}