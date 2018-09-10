#include "pch.h"
#include <stdio.h>
#include <iostream>
#include "CPullLamp.h"

CPullLamp::CPullLamp(int w1, int w2, int w3) : CLamp3Bulb(w1, w2, w3) {
	std::cout << "CPullLamp constructor called..." << std::endl;
}

CPullLamp::CPullLamp(int w1) : CLamp3Bulb(w1) {
	std::cout << "CPullLamp single integer constructor called..." << std::endl;
}

CPullLamp::~CPullLamp() {
	std::cout << "CPullLamp destructor called..." << std::endl;
}

void CPullLamp::Toggle() {
	if (GetState())
	{
		CLamp3Bulb::LampOff();
	}
	else {
		CLamp3Bulb::LampOn();
	}
}

