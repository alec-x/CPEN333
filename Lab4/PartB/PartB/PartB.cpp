// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#include <iostream>
#include "../../rt.h"

// Parent Process

int main()
{
	CTypedPipe<int> pipe1("Pipe1", 100);
	CTypedPipe<int> pipe2("Pipe2", 100);
	CTypedPipe<int> pipe3("Pipe3", 100);
	CTypedPipe<int> pipe4("Pipe4", 100);

	CProcess p1("C:\\Users\\alexv\\Documents\\Source\\Repos\\CPEN333\\Lab4\\PartB\\Debug\\Child1.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	CProcess p2("C:\\Users\\alexv\\Documents\\Source\\Repos\\CPEN333\\Lab4\\PartB\\Debug\\Child2.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	CProcess p3("C:\\Users\\alexv\\Documents\\Source\\Repos\\CPEN333\\Lab4\\PartB\\Debug\\Child3.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	CProcess p4("C:\\Users\\alexv\\Documents\\Source\\Repos\\CPEN333\\Lab4\\PartB\\Debug\\Child4.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	int out1, out2, out3, out4;
	for (int i = 0; i < 100; i++)
	{
		// Should seperate into threads (in the future) or else if nothing in pipe1 hangs
		pipe1.Read(&out1);
		pipe2.Read(&out2);
		pipe3.Read(&out3);
		pipe4.Read(&out4);

		printf("%d from Pipe 1\n", out1);
		printf("%d from Pipe 2\n", out2);
		printf("%d from Pipe 3\n", out3);
		printf("%d from Pipe 4\n", out4);
	}

	p1.WaitForProcess();
	p2.WaitForProcess();
	p3.WaitForProcess();
	p4.WaitForProcess();
}
