#include "Oil.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

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
