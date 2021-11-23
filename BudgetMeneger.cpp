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
            date = getTodayDate();
            break;
        case '2':
            date = setDate();
            break;
        default:
            cout << "Nie ma takiej opcji w menu. Spróbuj ponownie." << endl;
            system("pause");
            break;
        }
    }
    return date;
}

//int BudgetMeneger::setDate()
//{
//    string userDate = {""};
//    int date = 0;
//    cout << "Podaj datę w formacie: rrrr-mm-dd" << endl;
//    while(true)
//    {
//        cout << "Data: ";
//        userDate = SupportingMethods::loadLine();
//        if(isDateEnteredCorrectly(userDate) == false)
//        {
//            cout << "Podana data zostala wpisana nieprawidlowo. Podaj date w formacie: rrrr-mm-dd" << endl;
//        }
//        else
//        {
//            date = convertDateFromStringToInteger(userDate);
//            break;
//        }
//    }
//    return date;
//}

//int BudgetMeneger::getTodayDate()
//{
//    char day[3];
//    char month[3];
//    char year[5];
//    string dayStr, monthStr, yearStr, todayDate;
//    int intTodayDate;
//
//    time_t czas;
//    time( & czas );
//    tm czasTM = * localtime( & czas );
//
//    strftime( day, sizeof( day ), "%d", & czasTM );
//    strftime( month, sizeof( month ), "%m", & czasTM );
//    strftime( year, sizeof( year ), "%Y", & czasTM );
//    yearStr = year;
//    monthStr = month;
//    dayStr = day;
//    todayDate = yearStr + monthStr + dayStr;
//    intTodayDate = SupportingMethods::convertStringToInt(todayDate);
//    return intTodayDate;
//}
//
//bool BudgetMeneger::isDateEnteredCorrectly(string userDate)
//{
//    int intYear, intMonth, intDay;
//    char dateSign;
//    string year, month, day;
//    if (userDate.length()!=10 )
//    {
//        return false;
//    }
//    if(convertDateFromStringToInteger(userDate)>getTodayDate())
//    {
//        return false;
//    }
//    for(int i=0; i<userDate.length(); i++)
//    {
//        dateSign = userDate[i];
//        if((i == 4) || (i == 7))
//        {
//            if(dateSign != '-')
//                return false;
//        }
//        else
//        {
//            if((dateSign<'0') || (dateSign>'9'))
//                return false;
//            else if(i<4)
//                year += userDate[i];
//            else if((i>4) && (i<7))
//                month += userDate[i];
//            else
//                day += userDate[i];
//        }
//    }
//    intYear = SupportingMethods::convertStringToInt(year);
//    if(intYear<2000)
//        return false;
//    intMonth = SupportingMethods::convertStringToInt(month);
//    if(intMonth>12)
//        return false;
//    intDay = SupportingMethods::convertStringToInt(day);
//    if(intDay > howManyDaysInMonth(intMonth, intYear))
//        return false;
//
//    return true;
//}
//
//
//int BudgetMeneger::convertDateFromStringToInteger(string userDate)
//{
//    int date = 0;
//    string dateWithoutDashes;
//
//    for(int i=0; i<userDate.length(); i++)
//    {
//        if(userDate[i] != '-')
//            dateWithoutDashes += userDate[i];
//    }
//    date = SupportingMethods::convertStringToInt(dateWithoutDashes);
//    return date;
//}
//
//int BudgetMeneger::howManyDaysInMonth(int month, int year)
//{
//    int numberOfDays;
//    if (month == 4 || month == 6 || month == 9 || month == 11)
//    {
//        numberOfDays = 30;
//    }
//    else if (month == 2)
//    {
//        if (isYearLeap(year))
//            numberOfDays = 29;
//        else
//            numberOfDays = 28;
//    }
//    else
//    {
//        numberOfDays = 31;
//    }
//    return numberOfDays;
//}
//
//bool BudgetMeneger::isYearLeap(int year)
//{
//    if(((year % 4) == 0 && (year % 100)) != 0 || (year % 400) == 0)
//        return true;
//    return false;
//}

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
        if(getCurrentMonth() < incomes[i].getDate())
        {
            cout << "- " << incomes[i].getItem() << ": ";
            cout << "- " << incomes[i].getAmount() << endl;
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << endl;

    cout << " Wydatki: " << endl;
    for(int i=0; i<expences.size(); i++)
    {
        if(getCurrentMonth() < expences[i].getDate())
        {
            cout << "- " << expences[i].getItem() << ": ";
            cout << "- " << expences[i].getAmount() << endl;
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

//int BudgetMeneger::getCurrentMonth()
//{
//    int todayDate = getTodayDate();
//    int day;
//    day = todayDate%100;
//    todayDate -= day;
//    return todayDate;
//}

void BudgetMeneger::balanceOfPreviousMonth()
{
    float sumOfIncomes = 0;
    float sumOfExpense = 0;
    float subtractOfIncomesAndExpense = 0;
    int previousMonth = getPreviousMonth();
    int currentMonth = getCurrentMonth();
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
            cout << "- " << incomes[i].getAmount() << endl;
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
            cout << "- " <<expences[i].getAmount() << endl;
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

//int BudgetMeneger::getPreviousMonth()
//{
//    int currentMonth = getCurrentMonth();
//    int numberOfCurrentMonth = (currentMonth%10000)/100;
//    int previousMonth = 0;
//
//    if(numberOfCurrentMonth == 1)
//    {
//        previousMonth = currentMonth - 8900;
//    }
//    else
//    {
//        previousMonth = currentMonth - 100;
//    }
//    return previousMonth;
//}

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
    olderDate = setDate();
    cout << endl << "Nowsza data" << endl;
    newerDate = setDate();
    cout << endl << "Przychody: " << endl;
    for(int i=0; i<incomes.size(); i++)
    {
        date = incomes[i].getDate();
        if((date >= olderDate) && (date <= newerDate) )
        {
            cout << "- " << incomes[i].getItem() << ": ";
            cout << "- " << incomes[i].getAmount() << endl;
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
            cout << "- " <<expences[i].getAmount() << endl;
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
