#include "Receptionist.h"

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
    // TODO - implement Receptionist::MakeCoffee
    throw "Not yet implemented";
}

double Receptionist::GenerateInvoice()
{
    // TODO - implement Receptionist::GenerateInvoice
    throw "Not yet implemented";
}

bool Receptionist::StampServiceRecord()
{
    // TODO - implement Receptionist::StampServiceRecord
    throw "Not yet implemented";
}

Car Receptionist::GetCar()
{
    // TODO - implement Receptionist::GetCar
    throw "Not yet implemented";
}

Receptionist::Receptionist()
{
    // TODO - implement Receptionist::Receptionist
    throw "Not yet implemented";
}

Receptionist::~Receptionist()
{
    // TODO - implement Receptionist::~Receptionist
    throw "Not yet implemented";
}
