/*
ID: jgwilso1
PROG: friday
LANG: C++                 
*/

#include <iostream>
#include <map> 

using namespace std;

enum Day { // days % 7
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 0
};
enum Month {
    January = 1, 
    February = 2,
    March = 3,
    April = 4, 
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int N;
    cin >> N;

    int days = 1;
    int days_in_month = 0;

    map<int, int> map = {
        {Saturday, 0},
        {Sunday, 0},
        {Monday, 0},
        {Tuesday, 0},
        {Wednesday, 0},
        {Thursday, 0},
        {Friday, 0} };

    for (int y = 1900; y <= 1900 + N - 1; y++) {
        for (int m = January; m <= December; m++) { 
            if (m == February) { 
                // years divisible by 4 and not a century are leap years
                days_in_month = (y % 4 == 0 && y % 100 != 0) ? 29 : 28;
                // century years divisible by 400 are leap years
                if (y % 100 == 0 && y % 400 == 0) { 
                    days_in_month = 29;
                }
            }
            else if (m == September || m == April ||
                     m == June || m == November) {
                days_in_month = 30;
            }
            else {
                days_in_month = 31;
            }
            for (int d = 1; d <= days_in_month; d++) {
                if (d == 13) {
                    map[days % 7]++;
                }
                days++;
            }
        }
    }
    cout << map[Saturday] << " "
         << map[Sunday] << " "
         << map[Monday] << " "
         << map[Tuesday] << " "
         << map[Wednesday] << " "
         << map[Thursday] << " "
         << map[Friday] << endl;

    return 0;
}
