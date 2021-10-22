#include "SupportingMethods.h"

int SupportingMethods::convertStringToNumber(string number)
{
    int valor;
    stringstream ss(number);
    ss >> valor;
    return valor;
}

char SupportingMethods::enterSign()
{
    string enter = "";
    char sign;

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int SupportingMethods::enterInteger()
{
    string enter = "";
    int number = 0;

    while (true)
    {
        getline(cin, enter);

        stringstream myStream(enter);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string SupportingMethods::loadLine()
{
    string line = "";
    getline(cin, line);
    return line;
}
