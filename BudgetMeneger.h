#ifndef BUDGETMENEGER_H
#define BUDGETMENEGER_H

#include <iostream>
#include <vector>
#include <ctime>
#include "SupportingMethods.h"
#include "Incomes.h"
#include "Expense.h"

class BudgetMeneger
{
public:
    char chooseOptionFromUserMenu();
    void addIncomes();

private:
    int LOGGED_USER_ID;
    vector<Incomes> incomes;
    vector<Expense> expences;

    Incomes enterDetailsOfNewIncome();
    int setDateOfIncomeOrExpense();
    int getTodayDate();
    bool isDateEnteredCorrectly(string userDate);
    int convertDateFromStringToInteger(string userDate);
    int howManyDaysInMonth(int month, int year);
    bool isYearLeap(int year);

};

#endif // BUDGETMENEGER_H
