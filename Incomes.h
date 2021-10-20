#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include "Finances.h"

using namespace std;

class Incomes :public Finances
{
public:
    void setIncomeId(int newIncomeId);
    int getIncomeId();

private:
    int incomeId;
};

#endif // INCOMES_H
