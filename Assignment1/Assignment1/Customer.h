#pragma once
#include "..\rt.h"
#include "..\Transaction.h"

class Customer : public ActiveClass
{
public:
	Customer(); //includes init trans
	~Customer();
	// CSemaphore     ArrivalSemaphore, wait
	// CSemaphore     SwipeCardSemaphore, signal and send transaction in pipeline
    // Csemaphore     RemoveHoseSemaphore, signal
    // CSemaphore     SelectGradeSemaphore, signal
    // CSemaphore     DispenseGasSemaphore, wait
	// CSemaphore     ReturnHoseSemaphore, signal
	// CSemaphore     LeaveSemaphore, signal
private:
	int main(void); //includes init pipe
	Transaction customerTransaction;
};

