#ifndef   __CLamp3Bulb__
#define   __CLamp3Bulb__
#include "CSwitch.h"

class CLamp3Bulb {
	CSwitch bulbSwitch;

public:
	CLamp3Bulb(int w1, int w2, int w3);
	CLamp3Bulb();

	void LampOn();
	void LampOff();
	void GetState();
	void Print();
	int GetPower();

};

#endif 
