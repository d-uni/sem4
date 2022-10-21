#include <iostream>
#include <string>
#include <cmath>
#include "boost/date_time/posix_time/posix_time_types.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
using namespace std;
using namespace boost::gregorian;
int main()
{
    int year, month, day;
    long long int out = 0;
    char a;
    cin >> year >> a >> month >> a >> day;
    date d_1(year, month, day);
    while(cin >> year >> a >> month >> a >> day) {
        date d_2(year, month, day);
        out = out + abs((d_1 - d_2).days());
        d_1 = d_2;
    }
    cout << out << endl;
    return 0;
}