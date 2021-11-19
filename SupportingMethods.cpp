#include "SupportingMethods.h"

int SupportingMethods::convertStringToInt(std::string number)
{
    int valor;
    std::stringstream ss(number);
    ss >> valor;
    return valor;
}

float SupportingMethods::convertStringToFloat(std::string number)
{
    float valor;
    std::stringstream ss(number);
    ss >> valor;
    return valor;
}

char SupportingMethods::enterSign()
{
    std::string enter = "";
    char sign;

    while (true)
    {
        getline(std::cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        std::cout << "To nie jest pojedynczy znak. Wpisz ponownie." << std::endl;
    }
    return sign;
}

int SupportingMethods::enterInteger()
{
    std::string enter = "";
    int number = 0;

    while (true)
    {
        getline(std::cin, enter);

        std::stringstream myStream(enter);
        if (myStream >> number)
            break;
        std::cout << "To nie jest liczba. Wpisz ponownie. " << std::endl;
    }
    return number;
}

std::string SupportingMethods::loadLine()
{
    std::string line = "";
    getline(std::cin, line);
    return line;
}

std::string SupportingMethods::convertNumberToString(int number)
{
    std::ostringstream ss;
    ss << number;
    std::string str = ss.str();
    return str;
}

float SupportingMethods::roundFloat(float number)
{
    return round(number*100)/100;
}
