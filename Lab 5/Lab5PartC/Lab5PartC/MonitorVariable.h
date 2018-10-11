#pragma once
#include "../../rt.h"

class MonitorVariable {
	private:
		struct theDataInTheVariable {
			int value;
		};
		struct theDataInTheVariable *p;
		CDataPool *variableDataPool;	// Create DataPool for 
		CMutex *theMutex;
	public:
		// Constructor
		MonitorVariable(string variableName);

		// Destructor
		~MonitorVariable();

		void write(int input);

		int read();

		void increment();
};
