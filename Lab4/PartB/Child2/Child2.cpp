// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#include <iostream>
#include "../../rt.h"

int main()
{
	CTypedPipe<int> pipe2("Pipe2", 100);

	int send = 2;
	for (int i = 0; i < 100; i++)
	{
		pipe2.Write(&send);
	}

	return 0;
}
