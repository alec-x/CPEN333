#ifndef   __CLamp3Bulb__
#define   __CLamp3Bulb__
#include "CSwitch.h"
#include "CBulb.h"

class CLamp3Bulb {
	CBulb bulbArray[3];
	CSwitch mainSwitch;

public:
	CLamp3Bulb(int w1, int w2, int w3);
	~CLamp3Bulb();

	void LampOn();
	void LampOff();
	int GetState();
	void Print();
	int GetPower();

};

#endif 
