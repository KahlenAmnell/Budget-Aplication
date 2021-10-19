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
    int id = fetchNewUserId();
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

int UserMeneger::fetchNewUserId()
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
