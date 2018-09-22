#pragma once
#include "../rt.h"
#include <iostream>

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
		int accelRate = 7; // (m/s^2)
		int decelRate = 1; // (m/s^2)
		bool running = true;
};

