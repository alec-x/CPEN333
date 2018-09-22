#include "Car.h"
#include "../rt.h"

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

	while (running) {
		printf("Car %d: Speed %d\n", data, speed);
	}

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
	running = false;
}

int Car::getSpeed() {
	return speed;
}