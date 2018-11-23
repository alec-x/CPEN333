#ifndef OIL_H
#define OIL_H

#include <string>
using namespace std;

class Oil
{

private:
    string Type;
    int Quantity;

public:
    string getType();

    int getQuantity();

    Oil(string Type, int Quantity);

    ~Oil();
};

#endif
