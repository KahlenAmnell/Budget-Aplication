#include "DateMeneger.h"

int DateMeneger::setDate()
{
    string userDate = {""};
    int date = 0;
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
    return date;
}

int DateMeneger::getTodayDate()
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
    intTodayDate = SupportingMethods::convertStringToInt(todayDate);
    return intTodayDate;
}

bool DateMeneger::isDateEnteredCorrectly(string userDate)
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
    intYear = SupportingMethods::convertStringToInt(year);
    if(intYear<2000)
        return false;
    intMonth = SupportingMethods::convertStringToInt(month);
    if(intMonth>12)
        return false;
    intDay = SupportingMethods::convertStringToInt(day);
    if(intDay > howManyDaysInMonth(intMonth, intYear))
        return false;

    return true;
}


int DateMeneger::convertDateFromStringToInteger(string userDate)
{
    int date = 0;
    string dateWithoutDashes;

    for(int i=0; i<userDate.length(); i++)
    {
        if(userDate[i] != '-')
            dateWithoutDashes += userDate[i];
    }
    date = SupportingMethods::convertStringToInt(dateWithoutDashes);
    return date;
}

int DateMeneger::howManyDaysInMonth(int month, int year)
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

bool DateMeneger::isYearLeap(int year)
{
    if(((year % 4) == 0 && (year % 100)) != 0 || (year % 400) == 0)
        return true;
    return false;
}

int BudgetMeneger::getCurrentMonth()
{
    int todayDate = getTodayDate();
    int day;
    day = todayDate%100;
    todayDate -= day;
    return todayDate;
}

int BudgetMeneger::getPreviousMonth()
{
    int currentMonth = getCurrentMonth();
    int numberOfCurrentMonth = (currentMonth%10000)/100;
    int previousMonth = 0;

    if(numberOfCurrentMonth == 1)
    {
        previousMonth = currentMonth - 8900;
    }
    else
    {
        previousMonth = currentMonth - 100;
    }
    return previousMonth;
}

