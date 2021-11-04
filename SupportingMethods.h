#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

//using namespace std;

class SupportingMethods
{
public:
    static int convertStringToInt(std::string number);
    static float convertStringToFloat(std::string number);
    static char enterSign();
    static int enterInteger();
    static std::string loadLine();
    static std::string convertNumberToString(int number);

private:

};

#endif // SUPPORTINGMETHODS_H
