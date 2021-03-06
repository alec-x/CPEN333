#include <iostream>
#include "../rt.h"
// Alex Von Schulmann 13975140
// Alec Xu 38108130
/* Info:
 *	Single car,
 *	Holds 30 passengers,
 *	Waits to leave until full,
 *	Waits til all off until admitting more,
 *	Once off, passenger can immediately re-join queue.
 */

#define NUM_PASS 30
// Semaphores:
CSemaphore EntryGate("EntryGate", 0, 30);
CSemaphore ExitGate("ExitGate", 0, 30);
CSemaphore Empty("Empty", 0, 30);
CSemaphore Full("Full", 0, 30);

class Passenger : public ActiveClass
{
public: 	
	Passenger(int i) {
		passengerNum = i;
	} 
	int passengerNum;
	int count = 0;
private:
	int main(void)
	{
		while (1) {
			printf("Passenger %d queuing.\n", passengerNum);
			EntryGate.Wait();		// Queue (i.e. wait for rollercoaster to signal enough times to allow on)
			Full.Signal();			// Tell rollercoaster that passenger is boarded
			printf("Passenger %d boarded (and waiting for ride to end).\n", passengerNum);
			ExitGate.Wait();		// Wait until rollercoaster says passenger can get off
			Empty.Signal();			// Tell rollercoaster that the passenger is off
			printf("Passenger %d exited.\n", passengerNum);
			count++;
			printf("Passenger %d has ridden: %d times\n", passengerNum, count);
		}
		return 0;
	}
};

class RollerCoaster : public ActiveClass
{
public: 	RollerCoaster() { } 
private:
	int main(void)
	{
		while (1) {
			printf("Rollercoaster allowing passengers on...\n");
			for (int i = 0; i < NUM_PASS; i++)
			{
				EntryGate.Signal();	// Allow passengers to board.
			}
			SLEEP(1000);

			printf("Rollercoaster waiting until full...\n");
			for (int i = 0; i < NUM_PASS; i++)
			{
				Full.Wait();		// Wait until the rollercoaster is full of passengers.
			}
			SLEEP(1000);

			printf("Rollercoaster ride ended...\n");
			for (int i = 0; i < NUM_PASS; i++)
			{
				ExitGate.Signal();	// Signal to the passengers that the ride has ended.
			}
			SLEEP(1000);
			
			printf("Rollercoaster waiting until empty...\n");
			for (int i = 0; i < NUM_PASS; i++)
			{
				Empty.Wait();		// Wait until the rollercoaster is free of passengers.
			}
			SLEEP(1000);

		}
		return 0;
	}
};

int main()
{
	RollerCoaster car;						// Create rollercoaster
	car.Resume();							// Run rollercoaster

	SLEEP(1000);							// Wait for init.

	Passenger	*thePassengers[100];		// Create 100 Passenger ptrs

	for (int i = 0; i < 100; i++) {
		thePassengers[i] = new Passenger(i);	
		thePassengers[i]->Resume();
	}

	car.WaitForThread();
	return 0;
}
