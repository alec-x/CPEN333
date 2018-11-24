#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Car.h"
#include "JobSheet.h"
#include "Receptionist.h"
#include <iostream>

class Customer
{

private:
    class JobSheet* ServiceJobSheet;
    double Invoice;
    bool ServiceRecord;
	bool isHere;

public:
	class Car* CustomerCar;
	class Receptionist* theReceptionist;

    void ComeBackLater();
    void Leave();
	void ComeBack();

    void RecieveRecords(double cost);

    void Pay();

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
