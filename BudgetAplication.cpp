#include "BudgetAplication.h"

BudgetAplication::BudgetAplication(string nameOFFileWithUsers, string nameOfFileWithIncome, string nameOfFileWithExpense)
    :userMeneger()
{
    budgetMeneger = NULL;
}

BudgetAplication::~BudgetAplication()
{
    delete budgetMeneger;
    budgetMeneger = NULL;
}

char BudgetAplication::chooseOptionFromMainMenu()
{
    char choose;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = SupportingMethods::enterSign();

    return choose;
}

void BudgetAplication::userRegistration()
{
    userMeneger.userRegistration();
}

bool BudgetAplication::userLogIn()
{
    userMeneger.userLogIn();
    if (userMeneger.isUserAlreadyLogged())
    {
        budgetMeneger = new BudgetMeneger();
    }
    return userMeneger.isUserAlreadyLogged();
}

void BudgetAplication::changingPasswordOfLoggedInUser()
{

}

char BudgetAplication::chooseOptionFromUserMenu()
{
    return budgetMeneger->chooseOptionFromUserMenu();
}

void BudgetAplication::addIncomes()
{
    if (userMeneger.isUserAlreadyLogged())
    {
        budgetMeneger->addIncomes();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}
