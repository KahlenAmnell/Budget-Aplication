#ifndef BUDGETAPLICATION_H
#define BUDGETAPLICATION_H
//#define _GLIBCXX_USE_CXX11_ABI 0

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
    void addIncomes();
    void addExpense();
    void changePassword();
    void balanceOfCurrentMonth();

private:
    UserMeneger userMeneger;
    BudgetMeneger *budgetMeneger;
    const string NAME_OF_FILE_WITH_INCOME;
    const string NAME_OF_FILE_WITH_EXPENSE;
};

#endif // BUDGETAPLICATION_H
