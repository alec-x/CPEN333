#include "Customer.h"

void Customer::ComeBackLater()
{
	cout << "I, the Customer, am leaving to come back later" << endl;
	return;
}

void Customer::Leave()
{
	this->isHere = false;
	return;
}

void Customer::RecieveRecords(double cost, )
{
	this->AddJobSheet
}

void Customer::Pay(double Fee)
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

void Customer::GetServiceRecord()
{
	this->ServiceRecord = true;
	cout << "I, the Customer, have obtained the Service Record" << endl;
	return;
}

Customer::Customer()
{
	isHere = true;
	ServiceRecord = true;
	Invoice = 0;
	CustomerCar = new Car();
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
