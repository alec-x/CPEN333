#include "Customer.h"
#include "..\Transaction.h"
#include <stdlib.h>
// Alex Von Schulmann 13975140
// Alec Xu 38108130

Customer::Customer()
{
//generate random ccnumber some time
}


Customer::~Customer()
{
}

int Customer::main(void)
{
	//Initialize pipeline
	int pumpNum = rand() % 4;

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
	SwipeCardSemaphore.Signal();
	RemoveHoseSemaphore.Signal();
	SelectGradeSemaphore.Signal();
	DispenseGasSemaphore.Wait();
	ReturnHoseSemaphore.Signal();
	LeaveSemaphore.Signal();
	
	return 0; //kills the object we think
}
