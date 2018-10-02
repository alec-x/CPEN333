# include "Transaction.h"

Transaction::Transaction(string name, string ccNumber, int quantity, int grade)
{
	customerName = name;
	customerCreditCard = ccNumber;
	gasQuantity = quantity;
	gasGrade = grade;
}

Transaction::Transaction()
{
	customerName = "Alex von Schulmann";
	customerCreditCard = "1234567843218765";
	gasQuantity = 0;
	gasGrade = 1;
}

Transaction::~Transaction()
{

}

string Transaction::getCustomerName()
{
	return this->customerName;
}

string Transaction::getCustomerCreditCard()
{
	return this->customerCreditCard;
}

int Transaction::getGasQuantity()
{
	return this->gasQuantity;
}

int Transaction::getGasGrade()
{
	return this->gasGrade;
}
