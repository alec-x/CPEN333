// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#include "pch.h"
#include <stdio.h>
#include <iostream>
#include <array>
#include "CLamp3Bulb.h"



CLamp3Bulb::CLamp3Bulb(int w1, int w2, int w3) {
	bulbArray[0] = new CBulb(w1);
	bulbArray[1] = new CBulb(w2);
	bulbArray[2] = new CBulb(w3);
	mainSwitch = new CSwitch();
	std::cout << "CLamp3Bulb constructor being called..." << std::endl;
}

CLamp3Bulb::CLamp3Bulb(int w1) {
	bulbArray[0] = new CBulb(w1);
	bulbArray[1] = new CBulb(w1);
	bulbArray[2] = new CBulb(w1);
	mainSwitch = new CSwitch();
	std::cout << "CLamp3Bulb single integer constructor being called..." << std::endl;
}

CLamp3Bulb::CLamp3Bulb(const CLamp3Bulb &LampToCopy) {
	bulbArray[0] = new CBulb(LampToCopy.bulbArray[0]->getpower());
	bulbArray[1] = new CBulb(LampToCopy.bulbArray[1]->getpower());
	bulbArray[2] = new CBulb(LampToCopy.bulbArray[2]->getpower());
	mainSwitch = new CSwitch(LampToCopy.mainSwitch->getstate());
	if (mainSwitch->getstate())
	{
		this->LampOn();
	}
	std::cout << "CLamp3Bulb copy constructor being called..." << std::endl;
}

CLamp3Bulb::~CLamp3Bulb() {
	std::cout << "CLamp3Bulb destructor being called..." << std::endl;
	delete bulbArray[0];
	delete bulbArray[1];
	delete bulbArray[2];
	delete mainSwitch;
}

void CLamp3Bulb::LampOn() {
	mainSwitch->turnon();
	for (int i = 0; i < (sizeof(bulbArray) / sizeof(bulbArray[0])); i++)
	{
		bulbArray[i]->on();
	}
}

void CLamp3Bulb::LampOff() {
	mainSwitch->turnoff();
	for (int i = 0; i < (sizeof(bulbArray) / sizeof(bulbArray[0])); i++)
	{
		bulbArray[i]->off();
	}
}

int CLamp3Bulb::GetState() {
	return mainSwitch->getstate();
}

void CLamp3Bulb::Print() {
	mainSwitch->print();
}

int CLamp3Bulb::GetPower() {
	int totalPower = 0;
	if (mainSwitch->getstate())
	{
		for (int i = 0; i < (sizeof(bulbArray)/sizeof(bulbArray[0])); i++)
		{
			totalPower += bulbArray[i]->getpower();
		}
	}

	return totalPower;
}

CBulb* CLamp3Bulb::exchange(CBulb *newBulb, int bulbNumber) {
	CBulb* oldBulb = bulbArray[bulbNumber];
	bulbArray[bulbNumber] = newBulb;
	return oldBulb;
}