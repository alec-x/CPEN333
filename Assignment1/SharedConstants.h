#pragma once
#include <map>

#define NUMPUMPS 4
#define NUMPROCESS 3
const int grades[] = { 87, 89, 91, 93};
const map<int, int> gradeMap = {
	{ grades[0], 0},
	{ grades[1], 1},
	{ grades[2], 2},
	{ grades[3], 3}
};