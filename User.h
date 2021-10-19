#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
public:
    void setId(int newId);
    void setName(string newName);
    void setLastName(string newLastName);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getName();
    string getLastName();
    string getLogin();
    string getPassword();

private:
    int id;
    string name;
    string lastName;
    string login;
    string password;
};

#endif // USER_H
