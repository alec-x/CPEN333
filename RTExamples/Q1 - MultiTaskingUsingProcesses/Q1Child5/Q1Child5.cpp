#include "pch.h"
#include <stdio.h>
#include "..\..\rt.h"
// Author: Alec Xu 38108130
// Author: Alex von Schulmann 13975140
int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < 300; i++) {
		printf("# of arguments in child 5: %d\n", argc);
		for (i = 1; i < argc; i++) {
			printf("argument %d in child 5: %s\n", i, argv[i]);
		}	
		Sleep(50);
	}

	return 0;

}