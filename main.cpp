#include <iostream>

#include "Markup.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

string getTodayDate()
{
    char day[ 3 ];
    char month[3];
    char year[5];
	string dayStr, monthStr, yearStr, todayDate;

    time_t czas;
    time( & czas );
    tm czasTM = * localtime( & czas );

    strftime( day, sizeof( day ), "%d", & czasTM );
    strftime( month, sizeof( month ), "%m", & czasTM );
    strftime( year, sizeof( year ), "%Y", & czasTM );
    yearStr = year;
    monthStr = month;
    dayStr = day;
	todayDate = yearStr + "." + monthStr + "." + dayStr;
	return todayDate;
}

int main()
{
    vector<string> dates {"2021.10.14", "1991.12.01", "2012.01.01", "1991.11.30", "1991.12.02"};
    sort(dates.begin(), dates.end());
    for(auto a:dates)
    {
        cout << a << endl;
    }

    cout << getTodayDate() << endl;
    return 0;
}
