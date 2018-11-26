#include "Technician.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

JobSheet* Technician::ServiceCar(Car* CarServicing)
{
	GetCar(CarServicing);
	cout << "I, Jim, the Technician, have received the car\n";

	CurrentJobSheet = JobSheet();

	OilInventory = &(theStores->GetOil("Nice new oil", 10));
	CurrentJobSheet.AddItem(1, 10, 5.00);
	AirFilterInventory = &(theStores->GetAirFilter());
	CurrentJobSheet.AddItem(2, 1, 25.00);
	OilFilterInventory = &(theStores->GetOilFilter());
	CurrentJobSheet.AddItem(3, 1, 35.00);
	cout << "I, Jim, have picked up supplies from the store.\n";

	OilInventory = &(CurrentCar->SwapOil(*OilInventory));
	cout << "I, Jim, have swapped the oil.\n";
	theRecycling->Recycle(OilInventory);
	OilInventory = NULL;
	CurrentJobSheet.AddLabourItem("Oil Swap", 50.00);

	OilFilterInventory = &(CurrentCar->SwapOilFilter(*OilFilterInventory));
	cout << "I, Jim, have swapped the oil filter.\n";
	theGarbage->Dispose(*OilFilterInventory);
	OilFilterInventory = NULL;
	CurrentJobSheet.AddLabourItem("Oil Filter Swap", 29.99);

	AirFilterInventory = &(CurrentCar->SwapAirFilter(*AirFilterInventory));
	cout << "I, Jim, have swapped the air filter.\n";
	theGarbage->Dispose(*AirFilterInventory);
	AirFilterInventory = NULL;
	CurrentJobSheet.AddLabourItem("Air Filter Swap", 15.00);

	if (CurrentCar->CheckTiresForWear())
	{
		cout << "\"Oof, those tires are BALD\" - Jim\n";
		for (int i = 0; i < 4; i++)
		{
			TireInventory[i] = theStores->GetTires("Michelin", 19);
		}
		cout << "I, Jim, have picked up some fancy new tires\n";
		CurrentJobSheet.AddItem(4, 4, 100.00);

		for (int i = 0; i < 4; i++)
		{
			TireInventory[i] = CurrentCar->SwapTires(TireInventory[i], i);
			theRecycling->Recycle(TireInventory[i]);
			delete(TireInventory[i]); // Check if errors
		}
		CurrentJobSheet.AddLabourItem("Swapped Tires", 50.00);
	}
	else {
		CurrentCar->RotateTires();
		CurrentJobSheet.AddLabourItem("Rotated Tires", 50.00);
	}
	double temp = CurrentJobSheet.provideCostForInvoice();
	return &CurrentJobSheet;
}

void Technician::AddStores(Stores *aStores)
{
	theStores = aStores;
}

void Technician::DelStores()
{
	if (theStores != NULL) {
		theStores = NULL;
	}
}

void Technician::AddRecycling(Recycling *aRecycling)
{
	theRecycling = aRecycling;
}

void Technician::DelRecycling()
{
	if (theRecycling != NULL) {
		theRecycling = NULL;
	}
}

void Technician::AddGarbage(Garbage *aGarbage)
{
	theGarbage = aGarbage;
}

void Technician::DelGarbage()
{
	if (theGarbage != NULL) {
		theGarbage = NULL;
	}
}

void Technician::AddCar(Car *aCar)
{
	CurrentCar = aCar;
}

void Technician::DelCar()
{
	if (CurrentCar != NULL) {
		CurrentCar = NULL;
	}
}

void Technician::AddJobSheet(JobSheet *aJobSheet)
{
	CurrentJobSheet = *aJobSheet;
}

void Technician::DelJobSheet()
{
}

void Technician::GetCar(Car* carToService)
{
	CurrentCar = carToService;
}

Technician::Technician()
{
	OilInventory = NULL;
	AirFilterInventory = NULL;
	OilFilterInventory = NULL;
	CurrentCar = NULL;
	theStores = NULL;
	theRecycling = NULL;
	theGarbage = NULL;
}

Technician::~Technician()
{
}
