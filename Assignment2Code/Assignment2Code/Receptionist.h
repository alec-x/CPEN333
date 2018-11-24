#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "Car.h"
#include "JobSheet.h"
#include "Customer.h"
#include "Technician.h"
#include <iostream>

class Receptionist
{

private:
    bool ServiceRecord;
	class Technician* theTechnician;

public:
	class Customer* CustomerServicing;
	class JobSheet* CompletedJobSheet;
	class Car* CustomerCar;
	
	void setServiceRecord(bool state);

    bool MakeCoffee();

	void AddTechnician(Technician *aTechnician);
	void DelTechnician();

	void AddCustomer(Customer * aCustomer);
	void DelCustomer();

	void AddCar(Car * aCar);
	void DelCar();

	void AddJobSheet(JobSheet * aJobSheet);
	void DelJobSheet();

    double GenerateInvoice();

    void StampServiceRecord();

    Car GetCar();

    Receptionist();
	~Receptionist();
};

#endif
