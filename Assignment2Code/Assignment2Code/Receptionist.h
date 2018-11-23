#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "Car.h"
#include "JobSheet.h"
#include "Customer.h"
#include "Technician.h"

class Receptionist
{

private:
    class Car* CustomerCar;
	class JobSheet* CompletedJobSheet;
    bool ServiceRecord;
	class Technician* theTechnician;

public:
	class Customer* CustomerServicing;

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

    bool StampServiceRecord();

    Car GetCar();

    Receptionist();

    ~Receptionist();
};

#endif
