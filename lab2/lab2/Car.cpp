// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#include "Car.h"
#include "../rt.h"

UINT __stdcall speedoThreadInit(void *args)	// A thread function 
{
	int** argArray = (int**)args;
	
	while (**(argArray + 2))
	{
		printf("Car #%d speed: %d\n", 1 + **argArray, **(argArray + 1));
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
	int *argArray[] = { &data, &speed, &running };
	CThread* speedoThread = new CThread(speedoThreadInit, ACTIVE, &argArray);

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