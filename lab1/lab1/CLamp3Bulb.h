// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#ifndef   __CLamp3Bulb__
#define   __CLamp3Bulb__
#include "CSwitch.h"
#include "CBulb.h"

class CLamp3Bulb {
	CBulb *bulbArray[3];
	CSwitch *mainSwitch;

public:
	CLamp3Bulb(int w1, int w2, int w3);
	CLamp3Bulb(int w1);
	CLamp3Bulb(const CLamp3Bulb &LampToCopy);
	~CLamp3Bulb();

	void LampOn();
	void LampOff();
	int GetState();
	void Print();
	int GetPower();
	CBulb * exchange(CBulb * newBulb, int bulbNumber);

};

#endif 


