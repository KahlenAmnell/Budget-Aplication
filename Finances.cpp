#include "Finances.h"

void Finances::setUserId(int newUserId)
{
    userId = newUserId;
}

void Finances::setDate(int newDate)
{
    date = newDate;
}

void Finances::setAmount(int newAmount)
{
    amount = newAmount;
}

int Finances::getUserId()
{
    return userId;
}

int Finances::getDate()
{
    return date;
}

int Finances::getAmount()
{
    return amount;
}
