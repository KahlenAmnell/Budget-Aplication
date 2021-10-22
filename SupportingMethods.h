#ifndef SUPPORTINGMETHODS_H
#define SUPPORTINGMETHODS_H
//#define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class SupportingMethods
{
public:
    static int convertStringToNumber(string number);
    static char enterSign();
    static int enterInteger();
    static string loadLine();

private:

};

#endif // SUPPORTINGMETHODS_H
