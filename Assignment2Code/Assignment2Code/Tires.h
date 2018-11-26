#ifndef TIRES_H
#define TIRES_H

#include <string>
using namespace std;

// Alex Von Schulmann 13975140
// Alec Xu 38108130

class Tires
{

private:
    string Make;
    int Size;

public:
    string GetMake();
	int GetSize();

    Tires(string theMake, int theSize);
	Tires();
    ~Tires();
};

#endif
