#ifndef DATEMENEGER_H
#define DATEMENEGER_H

#include <ctime>
#include "SupportingMethods.h"

using namespace std;

class DateMeneger
{
public:
    int getTodayDate();
    bool isDateEnteredCorrectly(string userDate);
    int convertDateFromStringToInteger(string userDate);
    int howManyDaysInMonth(int month, int year);
    bool isYearLeap(int year);
    int getCurrentMonth();
    int getPreviousMonth();
    int setDate();
private:

};
#endif // DATEMENEGER_H
