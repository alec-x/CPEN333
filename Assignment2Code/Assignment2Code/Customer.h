#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Car.h"
#include "JobSheet.h"
#include "Receptionist.h"
#include <iostream>

class Customer
{

private:
    class Car* CustomerCar;
    class JobSheet* ServiceJobSheet;
    double Invoice;
    bool ServiceRecord;
	bool isHere;

public:
	class Receptionist* theReceptionist;

    void ComeBackLater();

    void Leave();

    void RecieveRecords(double cost);

    void Pay(double Fee);

	void AddCar(Car * aCar);
	void DelCar();

	void AddJobSheet(JobSheet * aJobSheet);
	void DelJobSheet();

    void GetCar(Car* theCar);

    void GetServiceRecord();

    Customer();

    ~Customer();

	void AddReceptionist(Receptionist * aReceptionist);
	void DelReceptionist();
};

#endif
