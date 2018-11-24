#include "Customer.h"

void Customer::ComeBackLater()
{
    // TODO - implement Customer::ComeBackLater
    throw "Not yet implemented";
}

void Customer::Leave()
{
    // TODO - implement Customer::Leave
    throw "Not yet implemented";
}

void Customer::RecieveRecords()
{
    // TODO - implement Customer::RecieveRecords
    throw "Not yet implemented";
}

void Customer::Pay(int double_Fee)
{
    // TODO - implement Customer::Pay
    throw "Not yet implemented";
}

void Customer::AddCar(Car *aCar)
{
	CustomerCar = aCar;
}

void Customer::DelCar()
{
	if (CustomerCar != NULL) {
		CustomerCar = NULL;
	}
}

void Customer::AddJobSheet(JobSheet *aJobSheet)
{
	ServiceJobSheet = aJobSheet;
}

void Customer::DelJobSheet()
{
	if (ServiceJobSheet != NULL) {
		ServiceJobSheet = NULL;
	}
}

Car Customer::GetCar()
{
    // TODO - implement Customer::GetCar
    throw "Not yet implemented";
}

bool Customer::GetServiceRecord()
{
    // TODO - implement Customer::GetServiceRecord
    throw "Not yet implemented";
}

Customer::Customer()
{
}

Customer::~Customer()
{
}

void Customer::AddReceptionist(Receptionist *aReceptionist)
{
	theReceptionist = aReceptionist;
	theReceptionist->CustomerServicing = this;
}

void Customer::DelReceptionist()
{
	if (theReceptionist != NULL) {
		theReceptionist->CustomerServicing = NULL;
		theReceptionist = NULL;
	}
}
