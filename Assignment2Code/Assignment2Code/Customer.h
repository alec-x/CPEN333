#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Car.h"
#include "JobSheet.h"
#include "Receptionist.h"

class Customer
{

private:
    Car CustomerCar;
    JobSheet ServiceJobSheet;
    double Invoice;
    bool ServiceRecord;
    class Receptionist* ReceptionistContact;

public:
    void ComeBackLater();

    void Leave();

    void RecieveRecords();

    void Pay(int double_Fee);

    Car GetCar();

    bool GetServiceRecord();

    Customer();

    ~Customer();
};

#endif
