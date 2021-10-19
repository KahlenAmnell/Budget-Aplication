#ifndef USERMENEGER_H
#define USERMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "SupportingMethods.h"

using namespace std;

class UserMeneger
{
public:
    UserMeneger();
    void userRegistration();

private:
    int loggedUserID;
    vector<User> users;

    User enterNewUserDetails();
    int fetchNewUserId();
    bool isLoginAlreadyExist(string login);

};

#endif // USERMENEGER_H
