#ifndef JOBSHEET_H
#define JOBSHEET_H
#include <iostream>
#include <vector>
#include <numeric>

// Alex Von Schulmann 13975140
// Alec Xu 38108130

using namespace std;

class JobSheet
{

private:
    std::vector<int> PartNumList;
    std::vector<int> QuantityList;
    std::vector<double> PartCostList;
    std::vector<string> TaskList;
    std::vector<double> TaskCostList;

public:
    void AddItem(int PartNumber, int Quantity, double Cost);
	void AddLabourItem(string Task, double Cost);
	double provideCostForInvoice();

    JobSheet();
    ~JobSheet();
};

#endif
