#include "BudgetAplication.h"

BudgetAplication::BudgetAplication(string nameOFFileWithUsers, string nameOfFileWithIncome, string nameOfFileWithExpense)
    :userMeneger(nameOFFileWithUsers), NAME_OF_FILE_WITH_INCOME(nameOfFileWithIncome), NAME_OF_FILE_WITH_EXPENSE(nameOfFileWithExpense)
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
    int loggedUserId = 0;
    userMeneger.userLogIn();
    if (userMeneger.isUserAlreadyLogged())
    {
        loggedUserId = userMeneger.getLoggedUserID();
        budgetMeneger = new BudgetMeneger(NAME_OF_FILE_WITH_INCOME, NAME_OF_FILE_WITH_EXPENSE, loggedUserId);
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

void BudgetAplication::addExpense()
{
    if (userMeneger.isUserAlreadyLogged())
    {
        budgetMeneger->addExpense();
    }
    else
    {
        cout << "Aby dodac wydatek, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void BudgetAplication::changePassword()
{
    if (userMeneger.isUserAlreadyLogged())
    {
        userMeneger.changingPasswordOfLoggedInUser();
    }
    else
    {
        cout << "Aby zmienic haslo, nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void BudgetAplication::balanceOfCurrentMonth()
{
    if (userMeneger.isUserAlreadyLogged())
    {
        budgetMeneger->balanceOfCurrentMonth();
    }
    else
    {
        cout << "Aby sprawdzic bilans z tego miesiaca nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void BudgetAplication::balanceOfPreviousMonth()
{
    if (userMeneger.isUserAlreadyLogged())
    {
        budgetMeneger->balanceOfPreviousMonth();
    }
    else
    {
        cout << "Aby sprawdzic bilans z poprzedniego miesiaca nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}

void BudgetAplication::balanceOfChosenPeriod()
{
    if (userMeneger.isUserAlreadyLogged())
    {
        budgetMeneger->balanceOfChosenPeriod();
    }
    else
    {
        cout << "Aby sprawdzic bilans z wybranego okresu nalezy najpierw sie zalogowac." << endl;
        system("pause");
    }
}
