#ifndef BUDGETAPLICATION_H
#define BUDGETAPLICATION_H

#include <iostream>

using namespace std;

class BudgetAplication
{
public:
    BudgetAplication(string nameOFFileWithUsers, string nameOfFileWithIncome, string nameOfFileWithExpense);
    ~BudgetAplication();
    char chooseOptionFromMainMenu();

private:
    const string NAME_OF_FILE_WITH_INCOME;
    const string NAME_OF_FILE_WITH_EXPENSE;
};

#endif // BUDGETAPLICATION_H
