#ifndef OIL_H
#define OIL_H

#include <string>
using namespace std;

// Alex Von Schulmann 13975140
// Alec Xu 38108130

class Oil
{

private:
    string Type;
    int Quantity;

public:
    string getType();

    int getQuantity();

    Oil(string Type, int Quantity);
	Oil();
    ~Oil();
};

#endif
