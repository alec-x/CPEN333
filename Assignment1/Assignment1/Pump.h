#pragma once
#include "../rt.h"

/* 
	Should be able to:
		- Communicate via Data Pool with the Gas Station Computer
		- i.e. send details of transaction (name, credit card, etc.)
		- then receive authorization token from GSC
		- then dispense gas and update GSC/Data Pool in 'real-time'
		- tell GSC done
*/

class Pump : public ActiveClass
{
	int data;

public:
	Pump();
	~Pump();

private:
	int main(void);

};