#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include "User.h"
#include "Markup.h"
#include "XMLFile.h"
#include "SupportingMethods.h"
#include <vector>

using namespace std;

class FileWithUsers :protected XmlFile
{
public:
    FileWithUsers(string nameOfFileWithUsers);
    void addUserToFile(User user);
    vector<User> loadUsersFromFile();
    void changePasswordInFile(int userId, string newPassword);
private:
    const string NAME_OF_FILE_WITH_USERS;
    void startTheFile(CMarkup &xml);
};
#endif // FILEWITHUSERS_H
