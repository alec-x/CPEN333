// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#include <iostream>
#include "../../rt.h"

int main()
{
	CTypedPipe<int> pipe1("Pipe1", 100);

	int send = 1;
	for (int i = 0; i < 100; i++)
	{
		pipe1.Write(&send);
		Sleep(500);
	}

	return 0;
}
