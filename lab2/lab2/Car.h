#pragma once
#include "../rt.h"
#include <iostream>
#include <cstdlib>


class Car: public ActiveClass
{
	int data;

	public:
		Car(int arg);
		Car();
		~Car();
		void Accelerate();
		void Cruise();
		void Stop();
		int getSpeed();

	private:
		int main(void);
		int speed = 0;
		int accelRate = 3; 
		int decelRate = 1;
		int running = 1;
};

