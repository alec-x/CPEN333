#include "JobSheet.h"

void JobSheet::AddItem(int PartNumber, int Quantity, double Cost)
{
	PartNumList.push_back(PartNumber);
	QuantityList.push_back(Quantity);
	PartCostList.push_back(Cost);
}

void JobSheet::AddLabourItem(string Task, double Cost)
{
	TaskList.push_back(Task);
	TaskCostList.push_back(Cost);
}

double JobSheet::provideCostForInvoice()
{
	double partCostSum = accumulate(PartCostList.begin(), PartCostList.end(), 0);
	double taskCostSum = accumulate(TaskCostList.begin(), TaskCostList.end(), 0);
	return partCostSum + taskCostSum;
}

JobSheet::JobSheet()
{
}

JobSheet::~JobSheet()
{
}
