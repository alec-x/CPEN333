#pragma once
#include "..\rt.h"
#include "..\Transaction.h"

class Customer : public ActiveClass {
	public:
		Customer(); // initializeTransaction
		~Customer();

		string firstNameArray[52] = {
			"Alex",
			"Alec",
			"Ebonie",
			"Verdie",
			"Lillia",
			"Jaimie",
			"Tiffaney",
			"Aracelis",
			"Jaunita",
			"Lenore",
			"Deon",
			"Chiquita",
			"Donn",
			"Barbara",
			"Callie",
			"Don",
			"Christy",
			"Magali",
			"Torie",
			"Charlie",
			"Bettyann",
			"Marisha",
			"Kathy",
			"Kirsten",
			"Lizabeth",
			"Sonya",
			"Bo",
			"Lindsey",
			"Latesha",
			"Heriberto",
			"Tess",
			"Charla",
			"Siu",
			"Boyd",
			"Merlene",
			"Yanira",
			"Ophelia",
			"Izetta",
			"Max",
			"Vanda",
			"Karisa",
			"Donnetta",
			"Gerardo",
			"Shanel",
			"Rima",
			"Penny",
			"Rena",
			"Lauran",
			"Lea",
			"Natalya",
			"Kyoko",
			"Lela"
		};
		string lastNameArray[40] = {
			"Turner",
			"Bush",
			"Adams",
			"Alexander",
			"Molina",
			"Clements",
			"Pena",
			"Duarte",
			"Potter",
			"Collier",
			"Welch",
			"Le",
			"Patterson",
			"Hale",
			"Wiley",
			"Edwards",
			"Cuevas",
			"Henson",
			"Casey",
			"Hammond",
			"Rollins",
			"Vang",
			"Andersen",
			"Baker",
			"Wilson",
			"Bauer",
			"Levy",
			"Herring",
			"Jensen",
			"Walker",
			"Trujillo",
			"Terry",
			"Lee",
			"Sampson",
			"Davies",
			"Schroeder",
			"Rowe",
			"Gibson",
			"Gilbert",
			"Leonard"
		};
		int fuelGradeArray[3] = {
			87,
			89,
			91
		};

	private:
		int main(void);
		// === MAIN FUNCTIONS ===
		// initializePipeline
		// CSemaphore     ArrivalSemaphore, wait
		// CSemaphore     SwipeCardSemaphore, signal and send transaction in pipeline
		// Csemaphore     RemoveHoseSemaphore, signal
		// CSemaphore     SelectGradeSemaphore, signal
		// CSemaphore     DispenseGasSemaphore, wait
		// CSemaphore     ReturnHoseSemaphore, signal
		// CSemaphore     LeaveSemaphore, signal
		Transaction customerTransaction;
		int pumpNum;
};

