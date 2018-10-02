#pragma once
#include "../rt.h"
#include <string.h>

/*

*/

class Transaction
{
public:
	Transaction(string name, string ccNumber, int quantity, int grade);
	Transaction();
	~Transaction();
	string getCustomerName();
	string getCustomerCreditCard();
	int getGasQuantity();
	int getGasGrade();
private:
	string customerName;
	string customerCreditCard;
	int gasQuantity;
	int gasGrade;
};