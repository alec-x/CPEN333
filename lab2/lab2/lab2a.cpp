#include "../rt.h"
#include "Car.h"

int main()
{
	Car* carGarage[10];
	for (int i = 0; i < 10; i++) 
	{
		carGarage[i] = new Car(i);
	}

	for (int i = 0; i < 10; i++)
	{
		carGarage[i]->Resume();
	}

	for (int i = 0; i < 10; i++)
	{
		carGarage[i]->WaitForThread();
	}

}