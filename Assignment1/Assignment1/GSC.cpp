#include "Pump.h"
#include <stdio.h>


// === STRUCT FOR ACCESSING DATA POOL ===
// ANY CHANGES HERE MUST ALSO BE MADE IN PUMP.H
struct PumpDataPoolData {
	Transaction tData;			// Customer transaction data
	int quantityFueled = 0;		// Progress in the fueling process
	bool complete = false;
	bool pumpOn = true;			// Kill the pump (set by the GSC)
	bool pumpPaused = false;	// In event of low fuel (set by GSC)
};

// === GLOBAL VARIABLES ===
PumpDataPoolData *pumpData[4];

// === THREAD FOR MONITORING A SINGLE PUMP ===
UINT __stdcall MonitorPumpData(void *args) // Takes in pumpNumber (same as in const.)
{	
	int pumpNumber = stoi(*(string *)(args)) - 1; // Array indexing [1 -> 0, 2 -> 1, etc.]
	string dataPoolName = "CDataPool" + to_string(pumpNumber);

	// Make/find data pool with data in the struct
	CDataPool dp(dataPoolName, sizeof(PumpDataPoolData));
	pumpData[pumpNumber] = (PumpDataPoolData *)(dp.LinkDataPool());

	while (pumpData[pumpNumber]->pumpOn)
	{
		// Write out
	}

	return 0;
}

UINT __stdcall MonitorFuelLevel(void *args) // Takes in pumpNumber (same as in const.)
{
	return 0;
}

int main() {

	// Make Threads to handle the CDataPools that communicate with the pumps
	CThread* pump1Thread = new CThread(MonitorPumpData, ACTIVE, "1");
	CThread* pump2Thread = new CThread(MonitorPumpData, ACTIVE, "2");
	CThread* pump3Thread = new CThread(MonitorPumpData, ACTIVE, "3");
	CThread* pump4Thread = new CThread(MonitorPumpData, ACTIVE, "4");

	// Make Thread to Handle Fuel Level Monitor
	// ... TO DO

	// Run-time display and operation
	// ... TO DO

	// Wait for threads to complete
	pump1Thread->WaitForThread();
	pump2Thread->WaitForThread();
	pump3Thread->WaitForThread();
	pump4Thread->WaitForThread();

	return 0;
}
