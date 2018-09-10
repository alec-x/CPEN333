#include "pch.h"
#include "CSwitch.h"
#include <iostream>
#include <stdio.h>
#include <string>

CSwitch::CSwitch() {
	state = 0;
	std::cout << "CSwitch default constructor being called..." << std::endl;
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

void CSwitch::print() {
	if (state == 1) {
		std::cout << "on" << std::endl;
	}
	else if (state == 0) {
		std::cout << "off" << std::endl;
	}
}