#include 	<stdio.h>
#include 	"C:\Users\alexv\Documents\Source\Repos\CPEN333\RTExamples\rt.h"			// change pathlist to this header file according to where it is stored
#include <string>


int 	main()
{
	printf("Creating Child Processes.....\n") ;
	 
//	Create process objects p1,p2 and p3. Arguments are as follows
//	1)	Pathlist to the child process executable i.e. the runnable child program
//	2)	The process priority. Allowable values are
//		HIGH_PRIORITY_CLASS	
//		IDLE_PRIORITY_CLASS
//		NORMAL_PRIORITY_CLASS	(this is the default if you do not specify). 
//		REALTIME_PRIORITY_CLASS 	(use with extreme caution)
//	3)	Whether the child process uses its own window or uses that of the parent. Values are
//		OWN_WINDOW or PARENT_WINDOW. Default is PARENT_WINDOW	 if not specified
//	4)	The initial processing state of the process, Allowable values are
//		ACTIVE or SUSPENDED. Default is ACTIVE if not specifie

	string repo = "C:\\Users\\alexv\\Documents\\Source\\Repos\\CPEN333\\RTExamples\\";

	CProcess p1(repo + "Q1 - MultiTaskingUsingProcesses\\Q1Child1\\debug\\Q1Child1.exe",	// pathlist to child program executable				
			NORMAL_PRIORITY_CLASS,			// priority
			PARENT_WINDOW,						// process has its own window					
			ACTIVE							// process is active immediately
	) ;


	CProcess p2(repo + "Q1 - MultiTaskingUsingProcesses\\Q1Child2\\debug\\Q1Child2.exe",	// pathlist to child program executable				
			NORMAL_PRIORITY_CLASS,			// priority
			PARENT_WINDOW,						// process has its own window					
			ACTIVE							// process is active immediately
	) ;

	CProcess p3(repo + "Q1 - MultiTaskingUsingProcesses\\Q1Child3\\debug\\Q1Child3.exe fred 1.2",	// pathlist to child program executable	plus some arguments		
			NORMAL_PRIORITY_CLASS,			// priority
			PARENT_WINDOW,						// process has its own window					
			ACTIVE
	);

	CProcess p4(repo + "Q1 - MultiTaskingUsingProcesses\\Release\\Q1Child4.exe",	// pathlist to child program executable	plus some arguments		
			NORMAL_PRIORITY_CLASS,			// priority
			PARENT_WINDOW,						// process has its own window					
			ACTIVE
	);
			
	printf("Child Processes Activated.....\n") ;

	printf("Waiting For Child1 to Terminate.....\n") ;
	p1.WaitForProcess() ;	
	
	printf("Waiting For Child2 to Terminate.....\n") ;
	p2.WaitForProcess() ;					

	printf("Suspending Child4....\n"); 
	p4.Suspend();

	printf("Waiting For Child3 to Terminate.....\n") ;
	p3.WaitForProcess() ;

	printf("Resuming Child4....\n"); 
	p4.Resume();

	printf("Waiting For Child4 to Terminate.....\n");
	p4.WaitForProcess();					

  	return 0 ;
}