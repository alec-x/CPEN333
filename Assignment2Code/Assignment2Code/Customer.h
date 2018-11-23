#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Car.h"
#include "JobSheet.h"
#include "Receptionist.h"

class Customer
{

private:
    class Car* CustomerCar;
    class JobSheet* ServiceJobSheet;
    double Invoice;
    bool ServiceRecord;

public:
	class Receptionist* theReceptionist;

    void ComeBackLater();

    void Leave();

    void RecieveRecords();

    void Pay(int double_Fee);

	void AddCar(Car * aCar);
	void DelCar();

	void AddJobSheet(JobSheet * aJobSheet);
	void DelJobSheet();

    Car GetCar();

    bool GetServiceRecord();

    Customer();

    ~Customer();

	void AddReceptionist(Receptionist * aReceptionist);
	void DelReceptionist();
};

#endif
