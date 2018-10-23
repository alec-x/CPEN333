#include "Customer.h"
#include "..\Transaction.h"
#include <stdlib.h>
// Alex Von Schulmann 13975140
// Alec Xu 38108130

Customer::Customer()
{
	// Randomly generate credit card
	for (int i = 0; i < sizeof(customerTransaction.ccNumber); i++)
	{
		customerTransaction.ccNumber[i] = '0' + (rand() % 10);
	}
	customerTransaction.ccNumber[17] = '\0';

	// Randomly generate name from array
	string name = firstNameArray[rand() % (sizeof(firstNameArray)/sizeof(firstNameArray[0]))] + " " + lastNameArray[rand() % (sizeof(lastNameArray)/sizeof(lastNameArray[0]))];
	strcpy_s(customerTransaction.customerName, sizeof(customerTransaction.customerName), name.c_str());

	// Randomly generate fuelGrade
	customerTransaction.fuelGrade = fuelGradeArray[rand() % (sizeof(fuelGradeArray)/sizeof(fuelGradeArray[0]))];

	// Randomly generate fuelAmount
	customerTransaction.fuelAmount = (rand() % 50) + 20; // From 20 - 70 L

	// Randomly generate pumpNum
	pumpNum = rand() % 4;

}


Customer::~Customer()
{
}

int Customer::main(void)
{
	// ===========
	// ===========
	// === TESTING
	/*
	printf("Credit Card No.: %s\n", customerTransaction.ccNumber);
	printf("Name: %s\n", customerTransaction.customerName);
	printf("Fuel Grade: %d\n", customerTransaction.fuelGrade);
	printf("Fuel Amount: %d\n", customerTransaction.fuelAmount);
	printf("Pump No.: %d\n\n", pumpNum);
	
	return 0;
	*/
	// === TESTING
	// ===========
	// ===========

	//Create necessary Semaphores
	CSemaphore ArrivalSemaphore("ArrivalSemaphore" + to_string(pumpNum), 0);  //wait
	CSemaphore SwipeCardSemaphore("SwipeCardSemaphore" + to_string(pumpNum), 0);// signal and send transaction in pipeline
	CSemaphore RemoveHoseSemaphore("RemoveHoseSemaphore" + to_string(pumpNum), 0);// signal
	CSemaphore SelectGradeSemaphore("SelectGradeSemaphore" + to_string(pumpNum), 0);// signal
	CSemaphore DispenseGasSemaphore("DispenseGasSemaphore" + to_string(pumpNum), 0);// wait
	CSemaphore ReturnHoseSemaphore("ReturnHoseSemaphore" + to_string(pumpNum), 0);// signal
	CSemaphore LeaveSemaphore("LeaveSemaphore" + to_string(pumpNum), 0);// signal
	//if weird errors, check semaphore intializations
	
	CTypedPipe<Transaction> customerPipeline("CustomerPipeline" + to_string(pumpNum), 1);
	ArrivalSemaphore.Wait();
	customerPipeline.Write(&customerTransaction);
	SLEEP(2000);
	SwipeCardSemaphore.Signal();
	RemoveHoseSemaphore.Signal();
	SelectGradeSemaphore.Signal();
	DispenseGasSemaphore.Wait();
	ReturnHoseSemaphore.Signal();
	LeaveSemaphore.Signal();
	
	printf("%s done\n", customerTransaction.customerName);

	return 0;
}
