#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "Car.h"
#include "JobSheet.h"
#include "Customer.h"

class Receptionist
{

private:
    Car CustomerCar;
    JobSheet CompletedJobsheet;
    class Customer* CustomerServicing;
    bool ServiceRecord;

public:
    bool MakeCoffee();

    double GenerateInvoice();

    bool StampServiceRecord();

    Car GetCar();

    Receptionist();

    ~Receptionist();
};

#endif
