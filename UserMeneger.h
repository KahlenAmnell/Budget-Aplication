#ifndef USERMENEGER_H
#define USERMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "SupportingMethods.h"
#include "FileWithUsers.h"

using namespace std;

class UserMeneger
{
public:
    UserMeneger(string nameOFFileWithUsers);
    void userRegistration();
    void userLogIn();
    bool isUserAlreadyLogged();
    int getLoggedUserID();
    void changingPasswordOfLoggedInUser();
    int getLoggedUserId();

private:
    int loggedUserID;
    vector<User> users;
    FileWithUsers fileWithUsers;

    User enterNewUserDetails();
    int getNewUserId();
    bool isLoginAlreadyExist(string login);


};

#endif // USERMENEGER_H
