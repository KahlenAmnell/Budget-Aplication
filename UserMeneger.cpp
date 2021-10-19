#include "UserMeneger.h"

UserMeneger::UserMeneger()
{

}

void UserMeneger::userRegistration()
{
    User user = enterNewUserDetails();

    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserMeneger::enterNewUserDetails()
{
    User user;
    int id = getNewUserId();
    user.setId(id);

    cout << "Podaj imię: ";
    user.setName(SupportingMethods::loadLine());
    cout << "Podaj nazwisko: ";
    user.setLastName(SupportingMethods::loadLine());
    do
    {
        cout << "Podaj login: ";
        user.setLogin(SupportingMethods::loadLine());
    } while (isLoginAlreadyExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(SupportingMethods::loadLine());

    return user;
}

int UserMeneger::getNewUserId()
{
    if(users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserMeneger::isLoginAlreadyExist(string login)
{
    for(int i=0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserMeneger::userLogIn()
{
    User user;
    string login = "", password = "";

    cout << "Podaj login: ";
    login = SupportingMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttemps = 3; numberOfAttemps > 0; numberOfAttemps--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttemps << ": ";
                password = SupportingMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserID = itr -> getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

bool UserMeneger::isUserAlreadyLogged()
{
    if(loggedUserID <= 0)
        return false;
    else
        return true;
}

int UserMeneger::getLoggedUserID()
{
    return loggedUserID;
}

void UserMeneger::changingPasswordOfLoggedInUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SupportingMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserID)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
   // plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
