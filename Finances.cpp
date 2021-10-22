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

void Finances::setName(string newName)
{
    name = newName;
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

string Finances::getName()
{
    return name;
}
