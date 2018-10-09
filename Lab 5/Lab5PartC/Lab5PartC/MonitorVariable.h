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
		MonitorVariable(string variableName) {
			theMutex = new CMutex("__MonitorVariableMutex__" + variableName);
			variableDataPool = new CDataPool("__MonitorVariableDataPool__" + variableName, sizeof(struct theDataInTheVariable));
			p = (struct theDataInTheVariable*)(variableDataPool->LinkDataPool());
			p->value = 0;
		}

		// Destructor
		~MonitorVariable() {
			delete theMutex;
			delete variableDataPool;
		}

		void write(int input) {
			theMutex->Wait();
			p->value = input;
			theMutex->Signal();
		}

		int read() {
			int data;
			theMutex->Wait();
			data = p->value;
			theMutex->Signal();
			return data;
		}

		void increment() {
			theMutex->Wait();
			p->value = p->value + 1;
			theMutex->Signal();
		}
};
