//#define _GLIBCXX_USE_CXX11_ABI 0
#include <iostream>

#include "Markup.h"
#include "BudgetAplication.h"


using namespace std;

int main()
{
    BudgetAplication budgetAplication("Users.xml", "Incomes.xml", "Expense.xml");
    char choose;
    bool isLogged = false;
    while(true)
     {
        if (isLogged == false)
        {
            choose = budgetAplication.chooseOptionFromMainMenu();

            switch (choose)
            {
            case '1':
                budgetAplication.userRegistration();
                break;
            case '2':
                isLogged = budgetAplication.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choose = budgetAplication.chooseOptionFromUserMenu();

            switch(choose)
            {
            case '1':
                budgetAplication.addIncomes();
                break;
            case '2':
                budgetAplication.addExpense();
            case '7':
                isLogged = false;
                break;
            default:
                cout << "Nie ma takiej opcji w menu. Spróbuj ponownie" << endl;
                break;
            }
        }
     }


}
