#include "Pump.h"
#include <stdio.h>
#include "PumpDataPoolData.h"

// === GLOBAL VARIABLES ===
PumpDataPoolData *pumpData[4];

// === THREAD FOR MONITORING A SINGLE PUMP ===
UINT __stdcall MonitorPumpData(void *args) // Takes in pumpNumber (same as in const.)
{	
	
	int pumpNumber = *(int *)(args) - 1; // Array indexing [1 -> 0, 2 -> 1, etc.]
	
	string dataPoolName = "CDataPool" + to_string(pumpNumber);

	// Make/find data pool with data in the struct
	CDataPool dp(dataPoolName, sizeof(PumpDataPoolData));
	pumpData[pumpNumber] = (PumpDataPoolData *)(dp.LinkDataPool());

	while (pumpData[pumpNumber]->pumpOn)
	{
		std::cout << "pump has fueled: " << pumpData[pumpNumber]->quantityFueled << " Gas" << std::endl;
	}
	return 0;
}

UINT __stdcall MonitorFuelLevel(void *args) // Takes in tankNumber (same as in const.)
{
	return 0;
}

int main() {
	const int numPumps = 1;
	Pump* pumpArray[numPumps];
	for (int i = 0; i < numPumps; i++)
	{
		pumpArray[i] = new Pump(i);
		pumpArray[i]->Resume();

		pumpArray[i]->dataPoolName;
		
	}
	CDataPool dp("CDataPoolPump0", sizeof(struct PumpDataPoolData));
	struct PumpDataPoolData *MyDataPool = (struct PumpDataPoolData *)(dp.LinkDataPool());
	MyDataPool->pumpOn = true;
	std::cout << "adding 30L of fuel to pump0" << std::endl;
	MyDataPool->quantityFueled = 30;
	std::cout << "There is: ";
	std::cout << MyDataPool->quantityFueled << "L of fuel in CDataPoolPump0" << std::endl;

	// Make Threads to handle the CDataPools that communicate with the pumps
	CThread* pumpMonitorArray[numPumps];
	for (int i = 0; i < numPumps; i++)
	{
		pumpMonitorArray[i] = new CThread(MonitorPumpData, ACTIVE, &i);
	}

	// Make Thread to Handle Fuel Level Monitor
	// ... TO DO

	// Run-time display and operation
	// ... TO DO
	// Test code
	for (int i = 0; i < numPumps; i++)
	{
		// Wait for threads to complete
		pumpMonitorArray[i]->WaitForThread();
	}
	

	
	

	

	return 0;
}
