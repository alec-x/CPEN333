#include "Customer.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

void Customer::ComeBackLater()
{
	cout << "I, the Customer, am leaving to come back later." << endl;
	ServiceRecord = false;
	return;
}

void Customer::ComeBack() {
	cout << "I, the Customer, have returned!\n";
	isHere = true;
}

void Customer::Leave()
{
	this->isHere = false;
	return;
}

void Customer::RecieveRecords(double cost)
{
	cout << "I, the Customer, have recieved, a JobSheet, Invoice, and stamped Service Record" << endl;
	AddJobSheet(this->theReceptionist->CompletedJobSheet);
	this->Invoice = cost;
	this->ServiceRecord = true;
	theReceptionist->DelJobSheet();
	theReceptionist->setServiceRecord(false);

	return;
}

void Customer::Pay()
{
	cout << "I, the Customer, have payed $" << Invoice << endl;
	return;
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

void Customer::GetCar(Car *theCar)
{
	cout << "I, the Customer, has taken back my Car" << endl;
	CustomerCar = theCar;
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
