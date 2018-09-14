// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#include "pch.h"
#include "CSwitch.h"
#include <iostream>
#include <stdio.h>
#include <string>

CSwitch::CSwitch() {
	state = 0;
	std::cout << "CSwitch default constructor being called..." << std::endl;
}

CSwitch::CSwitch(int initState) {
	state = initState;
 }

CSwitch::~CSwitch() {
	std::cout << "CSwitch destructor being called..." << std::endl;
}

void CSwitch::turnon() {
	state = 1;
}

void CSwitch::turnoff() {
	state = 0;
}

//required to complete exercise 3 although not specified to be created in lab
int CSwitch::getstate() {
	return state;
}

void CSwitch::print() {
	if (state == 1) {
		std::cout << "on" << std::endl;
	}
	else if (state == 0) {
		std::cout << "off" << std::endl;
	}
}