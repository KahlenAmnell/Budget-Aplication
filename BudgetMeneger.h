#ifndef BUDGETMENEGER_H
#define BUDGETMENEGER_H
//#define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "SupportingMethods.h"
#include "Incomes.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpense.h"
#include "DateMeneger.h"

class BudgetMeneger
{
public:
    BudgetMeneger(string nameOfFileWithIncomes, string nameOfFileWithExpense, int loggedUserId);
    char chooseOptionFromUserMenu();
    void addIncomes();
    void addExpense();
    void balanceOfCurrentMonth();
    void balanceOfPreviousMonth();
    void balanceOfChosenPeriod();

private:
    const int LOGGED_USER_ID = 0;
    vector<Incomes> incomes;
    vector<Expense> expences;
    FileWithIncomes fileWithIncomes;
    FileWithExpense fileWithExpense;
    DateMeneger dateMeneger;

    Incomes enterDetailsOfNewIncome();
    Expense enterDetailsOfNewExpsense();
    int setDateOfIncomeOrExpense();
    float enterAmount();
    void sortIncomesByDate();
    void sortExpencesByDate();
    void displayIncome(Incomes &income);
};

#endif // BUDGETMENEGER_H
