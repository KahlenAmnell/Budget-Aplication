#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Finances.h"

using namespace std;

class Expense
{
public:
    void setExpenseId(int newExpenseId);
    int getExpenseId();

private:
    int expenseId;
};

#endif // EXPENSE_H
