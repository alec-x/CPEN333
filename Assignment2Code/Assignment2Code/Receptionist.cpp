#include "Receptionist.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

void Receptionist::AddTechnician(Technician *aTechnician)
{
	theTechnician = aTechnician;
}

void Receptionist::DelTechnician()
{
	if (theTechnician != NULL) {
		theTechnician = NULL;
	}
}

void Receptionist::AddCustomer(Customer *aCustomer)
{
	CustomerServicing = aCustomer;
	CustomerServicing->theReceptionist = this;
}

void Receptionist::DelCustomer()
{
	if (CustomerServicing != NULL) {
		CustomerServicing->theReceptionist = NULL;
		CustomerServicing = NULL;
	}
}

void Receptionist::AddCar(Car *aCar)
{
	std::cout << "I, the Receptionist, have taken your car (and service record).\n";
	ServiceRecord = true;
	CustomerCar = aCar;
}

void Receptionist::DelCar()
{
	if (CustomerCar != NULL) {
		CustomerCar = NULL;
	}
}

void Receptionist::AddJobSheet(JobSheet *aJobSheet)
{
	CompletedJobSheet = aJobSheet;
}

void Receptionist::DelJobSheet()
{
	if (CompletedJobSheet != NULL) {
		CompletedJobSheet = NULL;
	}
}

bool Receptionist::MakeCoffee()
{
	std::cout << "I, the Receptionist, have made coffee. Huzzah!\n";
	return true;
}

double Receptionist::GenerateInvoice()
{
	return CompletedJobSheet->provideCostForInvoice();
}

void Receptionist::StampServiceRecord()
{
	std::cout << "I, the Receptionist, have stamped the service record.\n";
	ServiceRecord = false; 
}

Car Receptionist::GetCar()
{
	return *CustomerCar;
}

Receptionist::Receptionist()
{
	ServiceRecord = false;
	CustomerCar = NULL;
	CompletedJobSheet = NULL;
	theTechnician = NULL;
	CustomerServicing = NULL;
}

Receptionist::~Receptionist()
{
}
