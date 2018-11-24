#include "Tires.h"

string Tires::GetMake()
{
	return Make;
}

int Tires::GetSize()
{
	return Size;
}

Tires::Tires(string theMake, int theSize)
{
	Make = theMake;
	Size = theSize;
}

Tires::Tires()
{
	Make = "Michelin";
	Size = 19;
}

Tires::~Tires()
{
}
