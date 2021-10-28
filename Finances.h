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
    void setName(string newName);

    int getUserId();
    int getDate();
    float getAmount();
    string getName();

private:
    int userId;
    int date;
    float amount;
    string name;
};

#endif // FINANCES_H
