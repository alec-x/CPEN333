#ifndef TIRES_H
#define TIRES_H

#include <string>
using namespace std;

class Tires
{

private:
    string Make;
    int Size;

public:
    string GetMake();

    int GetSize();

    Tires(string Make, int Size);
	Tires();
    ~Tires();
};

#endif
