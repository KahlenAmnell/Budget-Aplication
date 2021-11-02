#include "Finances.h"

void Finances::setUserId(int newUserId)
{
    userId = newUserId;
}

void Finances::setDate(int newDate)
{
    date = newDate;
}

void Finances::setAmount(float newAmount)
{
    amount = newAmount;
}

void Finances::setItem(string newName)
{
    item = newName;
}

int Finances::getUserId()
{
    return userId;
}

int Finances::getDate()
{
    return date;
}

float Finances::getAmount()
{
    return amount;
}

string Finances::getItem()
{
    return item;
}
