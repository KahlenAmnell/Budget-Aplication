#include "FileWithUsers.h"

FileWithUsers::FileWithUsers(string nameOfFileWithUsers)
: XmlFile(nameOfFileWithUsers)
{

}

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if(!fileExists)
    {
        startTheFile(xml);
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("LastName", user.getLastName());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save("Users.xml");
}

vector<User> FileWithUsers::loadUsersFromFile()
{
    vector<User> users;
    User user;
    CMarkup xml;
    string stringUserId;
    int intUserId = 0;

    bool fileExists = xml.Load( "users.xml" );

    if(!fileExists)
    {
        return users;
    }

    xml.FindElem(); //Users
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();

        xml.FindElem("UserId");
        stringUserId = xml.GetData();
        intUserId = SupportingMethods::convertStringToNumber(stringUserId);
        user.setId(intUserId);

        xml.FindElem("Name");
        user.setName(xml.GetData());

        xml.FindElem("LastName");
        user.setLastName(xml.GetData());

        xml.FindElem("Login");
        user.setLogin(xml.GetData());

        xml.FindElem("Password");
        user.setPassword(xml.GetData());

        xml.OutOfElem();

        users.push_back(user);
    }
    return users;
}

void FileWithUsers::startTheFile(CMarkup &xml)
{
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
}

void FileWithUsers::changePasswordInFile(int userId, string newPassword)
{
    string stringUserId = SupportingMethods::convertNumberToString(userId);
    CMarkup xml;
    xml.Load( "Users.xml" );
    xml.FindElem(); //Users
    xml.IntoElem();
    while(xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if(xml.GetData() == stringUserId)
        {
            xml.FindElem("Password");
            xml.RemoveElem();
            xml.AddElem("Password", newPassword);
        }
        xml.OutOfElem();
    }
    xml.Save("Users.xml");
}
