#include "MonitorVariable.h"
// Authors:
// Alex Von Schulmann 13975140
// Alec Xu            38108130
MonitorVariable::MonitorVariable(string variableName) {
	theMutex = new CMutex("__MonitorVariableMutex__" + variableName);
	variableDataPool = new CDataPool("__MonitorVariableDataPool__" + variableName, sizeof(struct theDataInTheVariable));
	p = (struct theDataInTheVariable*)(variableDataPool->LinkDataPool());
	p->value = 0;
}

MonitorVariable::~MonitorVariable() {
	delete theMutex;
	delete variableDataPool;
}

void MonitorVariable::write(int input)
{
	theMutex->Wait();
	p->value = input;
	theMutex->Signal();
}

int MonitorVariable::read()
{
	int data;
	theMutex->Wait();
	data = p->value;
	theMutex->Signal();
	return data;
}

void MonitorVariable::increment()
{
	theMutex->Wait();
	p->value = p->value + 1;
	theMutex->Signal();
}
