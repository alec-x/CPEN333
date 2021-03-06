// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

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

	// Randomly tell the cars to 'Cruise' or 'Accelerate' n times
	int n = 100;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 10; i++)
		{
			int k = rand() % 2;
			switch (k)
			{
			case 0:
				carGarage[i]->Accelerate();
				break;
			case 1:
				carGarage[i]->Cruise();
				break;
			default:
				break;
			}
			Sleep(25);
		}
	}

	// Stop all cars
	for (int i = 0; i < 10; i++)
	{
		carGarage[i]->Stop();
	}


	// Wait for cars to finish running
	for (int i = 0; i < 10; i++)
	{
		carGarage[i]->WaitForThread();
	}

	printf("\n\n");
	for (int i = 0; i < 10; i++)
	{
		printf("Car #%d speed: %d\n", i + 1, carGarage[i]->getSpeed());
	}

	return 0;



}