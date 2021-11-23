#include "BudgetMeneger.h"

BudgetMeneger::BudgetMeneger(string nameOfFileWithIncomes, string nameOfFileWithExpense, int loggedUserId)
    : fileWithIncomes(nameOfFileWithIncomes), fileWithExpense(nameOfFileWithExpense), LOGGED_USER_ID(loggedUserId)
{
    incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_USER_ID);
    expences = fileWithExpense.loadExpenseFromFile(LOGGED_USER_ID);
}

char BudgetMeneger::chooseOptionFromUserMenu()
{
    char choose;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z bieżącego miesiąca" << endl;
    cout << "4. Bilans z poprzedniego miesiąca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choose = SupportingMethods::enterSign();

    return choose;
}

void BudgetMeneger::addIncomes()
{
    Incomes income;

    system ("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = enterDetailsOfNewIncome();

    incomes.push_back(income);

    fileWithIncomes.addNewIncomeToFile(income);

    system("pause");
}

Incomes BudgetMeneger::enterDetailsOfNewIncome()
{
    Incomes income;
    string item;
    int incomeId = fileWithIncomes.getLastIncomeId() +1;

    income.setIncomeId(incomeId);
    income.setUserId(LOGGED_USER_ID);
    income.setDate(setDateOfIncomeOrExpense());

    cout << "Podaj nazwe: ";
    item = SupportingMethods::loadLine();
    income.setItem(item);
    income.setAmount(enterAmount());

    return income;
}

void BudgetMeneger::addExpense()
{
    Expense expense;

    system ("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = enterDetailsOfNewExpsense();

    expences.push_back(expense);

    fileWithExpense.addNewExpenseToFile(expense);

    system("pause");
}


Expense BudgetMeneger::enterDetailsOfNewExpsense()
{
    Expense expense;
    string item;

    int expenseId = fileWithExpense.getLastExpanseId() +1;

    expense.setExpenseId(expenseId);
    expense.setUserId(LOGGED_USER_ID);
    expense.setDate(setDateOfIncomeOrExpense());

    cout << "Podaj nazwe: ";
    item = SupportingMethods::loadLine();
    expense.setItem(item);
    expense.setAmount(enterAmount());

    return expense;
}

int BudgetMeneger::setDateOfIncomeOrExpense()
{
    int date = 0;
    char choose = {'0'};

    cout << "Czy dotyczy dnia dzisiejszego? " << endl;
    cout << "1. Tak" << endl;
    cout << "2. Nie" << endl;

    while((choose != '1') && (choose != '2'))
    {

        cout << "Twój wybór: ";
        choose = SupportingMethods::enterSign();
        switch(choose)
        {
        case '1':
            date = dateMeneger.getTodayDate();
            break;
        case '2':
            date = dateMeneger.setDate();
            break;
        default:
            cout << "Nie ma takiej opcji w menu. Spróbuj ponownie." << endl;
            system("pause");
            break;
        }
    }
    return date;
}

float BudgetMeneger::enterAmount()
{
    string amount;
    float floatAmount;
    char amountSign;

    cout << "Podaj kwote: ";
    amount = SupportingMethods::loadLine();

    for(int i=0; i<amount.length(); i++)
    {
        amountSign = amount[i];
        if(amountSign == ',')
        {
            amount[i] = '.';
        }
    }

    floatAmount = stof(amount);

    return floatAmount;
}

void BudgetMeneger::sortIncomesByDate()
{
    sort( incomes.begin( ), incomes.end( ), [ ](Incomes& lhs, Incomes& rhs )
    {
        return lhs.getDate() < rhs.getDate();
    });
}

void BudgetMeneger::sortExpencesByDate()
{
    sort( expences.begin( ), expences.end( ), [ ](Expense& lhs, Expense& rhs )
    {
        return lhs.getDate() < rhs.getDate();
    });
}

void BudgetMeneger::balanceOfCurrentMonth()
{
    float sumOfIncomes = 0;
    float sumOfExpense = 0;
    float subtractOfIncomesAndExpense = 0;

    sortIncomesByDate();
    sortExpencesByDate();

    system ("cls");
    cout << " >>> BILANS Z BIEŻĄCEGO MIESIĄCA <<<" << endl << endl;
    cout << " Przychody: " << endl;
    for(int i=0; i<incomes.size(); i++)
    {
        if(dateMeneger.getCurrentMonth() < incomes[i].getDate())
        {
            cout << "- " << incomes[i].getItem() << ": ";
            cout << incomes[i].getAmount() << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << endl;

    cout << " Wydatki: " << endl;
    for(int i=0; i<expences.size(); i++)
    {
        if(dateMeneger.getCurrentMonth() < expences[i].getDate())
        {
            cout << "- " << expences[i].getItem() << ": ";
            cout << expences[i].getAmount() << endl;
            sumOfExpense += expences[i].getAmount();
        }
    }
    cout << endl;

    subtractOfIncomesAndExpense = sumOfIncomes - sumOfExpense;

    cout << "Suma przychodow: " << sumOfIncomes << endl;
    cout << "Suma wydatków: " << sumOfExpense << endl << endl;
    cout << "Różnica przychodów i wydatków: " << subtractOfIncomesAndExpense << endl;

    system("pause");
}

void BudgetMeneger::balanceOfPreviousMonth()
{
    float sumOfIncomes = 0;
    float sumOfExpense = 0;
    float subtractOfIncomesAndExpense = 0;
    int previousMonth = dateMeneger.getPreviousMonth();
    int currentMonth = dateMeneger.getCurrentMonth();
    int date = 0;

    sortIncomesByDate();
    sortExpencesByDate();

    system ("cls");
    cout << " >>> BILANS Z POPRZEDNIEGO MIESIĄCA <<<" << endl << endl;
    cout << "Przychody: " << endl;
    for(int i=0; i<incomes.size(); i++)
    {
        date = incomes[i].getDate();
        if((date > previousMonth) && (date < currentMonth) )
        {
            cout << "- " << incomes[i].getItem() << ": ";
            cout << incomes[i].getAmount() << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << endl;

    cout << "Wydatki: " << endl;
    for(int i=0; i<expences.size(); i++)
    {
        date = expences[i].getDate();
        if( (date > previousMonth) && (date < currentMonth) )
        {
            cout << "- " << expences[i].getItem() << ": ";
            cout << expences[i].getAmount() << endl;
            sumOfExpense += expences[i].getAmount();
        }
    }
    cout << endl;

    subtractOfIncomesAndExpense = sumOfIncomes - sumOfExpense;

    cout << "Suma przychodow: " << sumOfIncomes << endl;
    cout << "Suma wydatków: " << sumOfExpense << endl << endl;
    cout << "Różnica przychodów i wydatków: " << subtractOfIncomesAndExpense << endl;

    system("pause");
}

void BudgetMeneger::balanceOfChosenPeriod()
{
    float sumOfIncomes = 0;
    float sumOfExpense = 0;
    float subtractOfIncomesAndExpense = 0;
    int olderDate = 0;
    int newerDate = 0;
    int date = 0;

    sortIncomesByDate();
    sortExpencesByDate();

    system ("cls");
    cout << " >>> BILANS Z WYBRANEGO OKRESU <<<" << endl << endl;
    cout << endl << "Starsza data" << endl;
    olderDate = dateMeneger.setDate();
    cout << endl << "Nowsza data" << endl;
    newerDate = dateMeneger.setDate();
    cout << endl << "Przychody: " << endl;
    for(int i=0; i<incomes.size(); i++)
    {
        date = incomes[i].getDate();
        if((date >= olderDate) && (date <= newerDate) )
        {
            cout << "- " << incomes[i].getItem() << ": ";
            cout << incomes[i].getAmount() << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << endl;

    cout << "Wydatki: " << endl;
    for(int i=0; i<expences.size(); i++)
    {
        date = expences[i].getDate();
        if( (date >= olderDate) && (date <= newerDate) )
        {
            cout << "- " << expences[i].getItem() << ": ";
            cout << expences[i].getAmount() << endl;
            sumOfExpense += expences[i].getAmount();
        }
    }
    cout << endl;

    subtractOfIncomesAndExpense = sumOfIncomes - sumOfExpense;

    cout << "Suma przychodow: " << sumOfIncomes << endl;
    cout << "Suma wydatków: " << sumOfExpense << endl << endl;
    cout << "Różnica przychodów i wydatków: " << subtractOfIncomesAndExpense << endl;

    system("pause");
}
