#include <iostream>
#include "../../rt.h"

int main()
{
	CTypedPipe<int> pipe4("Pipe4", 100);

	int send = 4;
	for (int i = 0; i < 100; i++)
	{
		pipe4.Write(&send);
	}

	return 0;
}
