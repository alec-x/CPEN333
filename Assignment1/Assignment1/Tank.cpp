#include "Tank.h"

Tank::Tank(int tankNumber)
{
	dataPoolName = "CDataPoolTank" + to_string(tankNumber);
	dataPipeName = "CPipeTank" + to_string(tankNumber);
}

Tank::~Tank()
{
}
