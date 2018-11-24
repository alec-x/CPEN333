#include "Oil.h"

string Oil::getType()
{
	return this->Type;
}

int Oil::getQuantity()
{
	return this->Quantity;
}

Oil::Oil(string Type, int Quantity)
{
	this->Type = Type;
	this->Quantity = Quantity;
}

Oil::Oil()
{
}

Oil::~Oil()
{
}
