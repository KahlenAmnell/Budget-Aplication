#ifndef BUDGETMENEGER_H
#define BUDGETMENEGER_H
//#define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "SupportingMethods.h"
#include "Incomes.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpense.h"

class BudgetMeneger
{
public:
    BudgetMeneger(string nameOfFileWithIncomes, string nameOfFileWithExpense, int loggedUserId);
    char chooseOptionFromUserMenu();
    void addIncomes();
    void addExpense();

private:
    const int LOGGED_USER_ID = 0;
    vector<Incomes> incomes;
    vector<Expense> expences;
    FileWithIncomes fileWithIncomes;
    FileWithExpense fileWithExpense;

    Incomes enterDetailsOfNewIncome();
    Expense enterDetailsOfNewExpsense();
    int setDateOfIncomeOrExpense();
    int getTodayDate();
    bool isDateEnteredCorrectly(string userDate);
    int convertDateFromStringToInteger(string userDate);
    int howManyDaysInMonth(int month, int year);
    bool isYearLeap(int year);
    float enterAmount();

};

#endif // BUDGETMENEGER_H
