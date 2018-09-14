// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#ifndef   __CPullLamp__
#define   __CPullLamp__
#include "CLamp3Bulb.h"

class CPullLamp : public CLamp3Bulb
{

	public:
		CPullLamp(int w1, int w2, int w3);
		CPullLamp(int w1);
		~CPullLamp();
		void Toggle();

	private:
		void LampOn() {}
		void LampOff() {}
};

#endif
