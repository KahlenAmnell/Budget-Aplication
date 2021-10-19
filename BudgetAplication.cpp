#include "BudgetAplication.h"

BudgetAplication::BudgetAplication(string nameOFFileWithUsers, string nameOfFileWithIncome, string nameOfFileWithExpense)
{

}

BudgetAplication::~BudgetAplication()
{

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
    choose = getchar();
   // choose = SupportingMethods::enterSing();

    return choose;
}
