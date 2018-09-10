#include "pch.h"
#include <stdio.h>
#include <iostream>
#include "pch.h"
#include "CLamp3Bulb.h"
#include <array>


CLamp3Bulb::CLamp3Bulb(int w1, int w2, int w3) {
	bulbArray[0].setwatts(w1); // ask how we could use the overloaded constructor instead
	bulbArray[1].setwatts(w2);
	bulbArray[2].setwatts(w3);
	std::cout << "CLamp3Bulb constructor being called..." << std::endl;
}

CLamp3Bulb::~CLamp3Bulb() {
	std::cout << "CLamp3Bulb destructor being called..." << std::endl;
}

void CLamp3Bulb::LampOn() {
	mainSwitch.turnon();
	for (int i = 0; i < (sizeof(bulbArray) / sizeof(bulbArray[0])); i++)
	{
		bulbArray[i].on();
	}
}

void CLamp3Bulb::LampOff() {
	mainSwitch.turnoff();
	for (int i = 0; i < (sizeof(bulbArray) / sizeof(bulbArray[0])); i++)
	{
		bulbArray[i].off();
	}
}

int CLamp3Bulb::GetState() {
	return mainSwitch.getstate();
}

void CLamp3Bulb::Print() {
	mainSwitch.print();
}

int CLamp3Bulb::GetPower() {
	int totalPower = 0;
	if (mainSwitch.getstate())
	{
		for (int i = 0; i < (sizeof(bulbArray)/sizeof(bulbArray[0])); i++)
		{
			totalPower += bulbArray[i].getpower();
		}
	}

	return totalPower;
}