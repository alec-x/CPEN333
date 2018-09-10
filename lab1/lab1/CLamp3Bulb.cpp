#include "pch.h"
#include <stdio.h>
#include <iostream>
#include "CLamp3Bulb.h"
#include "CSwitch.h"


CLamp3Bulb::CLamp3Bulb(int w1, int w2, int w3) {
	std::cout << "CLamp3Bulb constructor being called..." << std::endl;
	bulb1 = CBulb(w1);
	bulb2 = CBulb(w2);
	bulb3 = CBulb(w3);
	mainSwitch = CSwitch();
}

CLamp3Bulb::~CLamp3Bulb() {
	std::cout << "CLamp3Bulb destructor being called..." << std::endl;
}

void CLamp3Bulb::LampOn() {

}

void CLamp3Bulb::LampOff() {

}

void CLamp3Bulb::GetState() {

}

void CLamp3Bulb::Print() {

}

int CLamp3Bulb::GetPower() {

}