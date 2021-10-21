#include "BudgetMeneger.h"

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

    //saving to file

    system("pause");
}

Incomes BudgetMeneger::enterDetailsOfNewIncome()
{
    Incomes income;

    //get last income id from file

    income.setUserId(LOGGED_USER_ID);

    income.setDate(setDateOfIncomeOrExpense());

    //ustawianie nazwy

    // ustawianie kwoty

    return income;
}

int BudgetMeneger::setDateOfIncomeOrExpense()
{
    int date = 0;
    string userDate = {""};
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
            cout << "Podaj datę w formacie: rrrr-mm-dd" << endl;
            while(true)
            {
                cout << "Data: ";
                userDate = SupportingMethods::loadLine();
                if(isDateEnteredCorrectly(userDate) == false)
                    {
                        cout << "Podana data zostala wpisana nieprawidlowo. Podaj date w formacie: rrrr-mm-dd" << endl;
                    }
                else
                    {
                        date = convertDateFromStringToInteger(userDate);
                        break;
                    }
            }
            break;
        default:
            cout << "Nie ma takiej opcji w menu. Spróbuj ponownie." << endl;
            system("pause");
            break;
        }
    }
    return date;
}

int BudgetMeneger::getTodayDate()
{
    char day[3];
    char month[3];
    char year[5];
    string dayStr, monthStr, yearStr, todayDate;
    int intTodayDate;

    time_t czas;
    time( & czas );
    tm czasTM = * localtime( & czas );

    strftime( day, sizeof( day ), "%d", & czasTM );
    strftime( month, sizeof( month ), "%m", & czasTM );
    strftime( year, sizeof( year ), "%Y", & czasTM );
    yearStr = year;
    monthStr = month;
    dayStr = day;
    todayDate = yearStr + monthStr + dayStr;
    intTodayDate = SupportingMethods::convertStringToInteger(todayDate);
    return intTodayDate;
}

bool BudgetMeneger::isDateEnteredCorrectly(string userDate)
{
    int intYear, intMonth, intDay;
    char dateSign;
    string year, month, day;
    if (userDate.length()!=10 )
    {
        return false;
    }
    if(convertDateFromStringToInteger(userDate)>getTodayDate())
    {
        return false;
    }
    for(int i=0; i<userDate.length(); i++)
    {
        dateSign = userDate[i];
        if((i == 4) || (i == 7))
        {
            if(dateSign != '-')
                return false;
        }
        else
        {
            if((dateSign<'0') || (dateSign>'9'))
                return false;
            else if(i<4)
                year += userDate[i];
            else if((i>4) && (i<7))
                month += userDate[i];
            else
                day += userDate[i];
        }
    }
    intYear = SupportingMethods::convertStringToInteger(year);
    if(intYear<2000)
        return false;
    intMonth = SupportingMethods::convertStringToInteger(month);
    if(intMonth>12)
        return false;
    intDay = SupportingMethods::convertStringToInteger(day);
    if(intDay > howManyDaysInMonth(intMonth, intYear))
        return false;

    return true;
}


int BudgetMeneger::convertDateFromStringToInteger(string userDate)
{
    int date = 0;
    string dateWithoutDashes;

    for(int i=0; i<userDate.length(); i++)
    {
        if(userDate[i] != '-')
            dateWithoutDashes += userDate[i];
    }
    date = SupportingMethods::convertStringToInteger(dateWithoutDashes);
    return date;
}

int BudgetMeneger::howManyDaysInMonth(int month, int year)
{
    int numberOfDays;
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        numberOfDays = 30;
    }
    else if (month == 2)
    {
        if (isYearLeap(year))
            numberOfDays = 29;
        else
            numberOfDays = 28;
    }
    else
    {
        numberOfDays = 31;
    }
    return numberOfDays;
}

bool BudgetMeneger::isYearLeap(int year)
{
    if(((year % 4) == 0 && (year % 100)) != 0 || (year % 400) == 0)
        return true;
    return false;
}
