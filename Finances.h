#ifndef FINANCES_H
#define FINANCES_H

#include <iostream>

using namespace std;

class Finances
{
public:
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setAmount(float newAmount);
    void setItem(string newName);

    int getUserId();
    int getDate();
    float getAmount();
    string getItem();

private:
    int userId;
    int date;
    float amount;
    string item;
};

#endif // FINANCES_H
