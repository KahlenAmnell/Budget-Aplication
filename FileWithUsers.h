#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
public:
    FileWithUsers();
    void addUserToFile();
private:
    string nameOfFileWithUsers;
};
#endif // FILEWITHUSERS_H
