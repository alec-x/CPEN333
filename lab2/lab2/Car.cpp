#include "Car.h"
#include "../rt.h"

UINT __stdcall speedoThreadInit(void *args)	// A thread function 
{
	int* speed = (int*)args;
	
	for (size_t i = 0; i < 10; i++)
	{
		printf("Child: %d\n", *speed);
		Sleep(2000);
	}


	return 0;
}

Car::Car(int arg)
{
	data = arg;
}

Car::Car()
{
	data = NULL;
}

Car::~Car()
{

}

int Car::main(void)
{
	CThread* speedoThread = new CThread(speedoThreadInit, ACTIVE, &speed);

	speedoThread->WaitForThread();
	delete speedoThread;

	return 0;
}

void Car::Accelerate() {
	speed += accelRate;
}

void Car::Cruise() {
	if (speed > decelRate)
	{
		speed -= decelRate;
	}
}

void Car::Stop() {
	running = 0;
}

int Car::getSpeed() {
	return speed;
}