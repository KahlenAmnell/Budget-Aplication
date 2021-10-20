#ifndef BUDGETAPLICATION_H
#define BUDGETAPLICATION_H

#include <iostream>
#include "UserMeneger.h"
#include "BudgetMeneger.h"
#include "SupportingMethods.h"

using namespace std;

class BudgetAplication
{
public:
    BudgetAplication(string nameOFFileWithUsers, string nameOfFileWithIncome, string nameOfFileWithExpense);
    ~BudgetAplication();
    char chooseOptionFromMainMenu();
    void userRegistration();
    bool userLogIn();
    void changingPasswordOfLoggedInUser();

    char chooseOptionFromUserMenu();

private:
    UserMeneger userMeneger;
    BudgetMeneger *budgetMeneger;
    const string NAME_OF_FILE_WITH_INCOME;
    const string NAME_OF_FILE_WITH_EXPENSE;
};

#endif // BUDGETAPLICATION_H
