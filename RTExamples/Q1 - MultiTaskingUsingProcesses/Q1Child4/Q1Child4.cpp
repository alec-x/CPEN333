#include "pch.h"
#include <stdio.h>
#include "..\..\rt.h"

int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < 300; i++) {
		printf("Hello from child process 4....\n");
		Sleep(50);
	}

	return 0;

}