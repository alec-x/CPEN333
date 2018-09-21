#include "Car.h"
#include "../rt.h"

Car::Car(int arg)
{
	data = arg;
}

Car::Car()
{
}

Car::~Car()
{
}

int Car::main(void)
{
	for (int i = 0; i < 1000; i++) 
	{
		printf("Hello, I am car %d!\n", data);
	}
	return 0;
}