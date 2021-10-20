#ifndef BUDGETMENEGER_H
#define BUDGETMENEGER_H

#include <iostream>
#include <vector>
#include "SupportingMethods.h"
#include "Incomes.h"
#include "Expense.h"

class BudgetMeneger
{
public:
    char chooseOptionFromUserMenu();

private:
    int LOGGED_USER_ID;
    vector<Incomes> incomes;
    vector<Expense> expences;


};

#endif // BUDGETMENEGER_H
