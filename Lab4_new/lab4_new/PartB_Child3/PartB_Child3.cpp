#include <iostream>
#include "../../rt.h"

int main()
{
	CTypedPipe<int> pipe3("Pipe3", 100);

	int send = 3;
	for (int i = 0; i < 100; i++)
	{
		pipe3.Write(&send);
	}

	return 0;
}
