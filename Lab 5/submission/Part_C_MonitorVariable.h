#pragma once
#include "../../rt.h"
// Authors:
// Alex Von Schulmann 13975140
// Alec Xu            38108130
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
