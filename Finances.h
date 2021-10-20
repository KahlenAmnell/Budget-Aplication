#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

using namespace std;

class Finances
{
public:
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setAmount(int newAmount);

    int getUserId();
    int getDate();
    int getAmount();

private:
    int userId;
    int date;
    int amount;
};

#endif // FINANCES_H
