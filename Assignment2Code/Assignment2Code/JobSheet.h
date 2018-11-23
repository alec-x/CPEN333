#ifndef JOBSHEET_H
#define JOBSHEET_H

#include <list>

using namespace std;

class JobSheet
{

private:
    std::list<int> PartNumList;
    std::list<int> QuantityList;
    std::list<double> PartCostList;
    std::list<string> TaskList;
    std::list<double> TaskCostList;

public:
    void AddItem(int PartNumber, int Quantity, int double_Cost);

    void AddLabourItem(string Task, int double_Cost);

    JobSheet();

    ~JobSheet();
};

#endif
