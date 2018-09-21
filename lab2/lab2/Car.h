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

	private:
		int main(void);
};

