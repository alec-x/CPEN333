#include <iostream>
#include "Oil.h"
#include "Tires.h"
#include "AirFilter.h"
#include "OilFilter.h"
#include "JobSheet.h"
#include "Car.h"
#include "Stores.h"
#include "Recycling.h"
#include "Garbage.h"
#include "Technician.h"
#include "Customer.h"
#include "Receptionist.h"

using namespace std;

// Alex Von Schulmann 13975140
// Alec Xu 38108130

int main()
{
	Customer* RudeMan = new Customer();
	Receptionist* Sarah = new Receptionist();
	Technician* Jim = new Technician();
	Stores* ourStores = new Stores();
	Garbage* theDump = new Garbage();
	Recycling* theReturnItDepot = new Recycling();

	RudeMan->AddReceptionist(Sarah);
	Sarah->AddTechnician(Jim);
	Jim->AddGarbage(theDump);
	Jim->AddRecycling(theReturnItDepot);
	Jim->AddStores(ourStores);

	Sarah->AddCar(RudeMan->CustomerCar);
	RudeMan->DelCar();
	RudeMan->ComeBackLater();

	Sarah->CompletedJobSheet = Jim->ServiceCar(Sarah->CustomerCar);
	Jim->DelJobSheet();
	Sarah->CustomerCar = Jim->CurrentCar;
	Jim->DelCar();
	Sarah->MakeCoffee();

	Sarah->StampServiceRecord();
	RudeMan->ComeBack();
	RudeMan->RecieveRecords(Sarah->GenerateInvoice());
	RudeMan->Pay();
	RudeMan->CustomerCar = &(Sarah->GetCar());

	cout << "The End.\n";

	delete(RudeMan);
	delete(Sarah);
	delete(Jim);
	delete(ourStores);
	delete(theDump);
	delete(theReturnItDepot);
}