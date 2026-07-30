#include <iostream>
using namespace std;

string dayOfWeek(int d, int m, int y) {
    //if the month is January or February, we treat it as the 13th or 14th month of the previous year
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }

    int K = y % 100;
    int J = y / 100;
//this is zeller's congruence formula to calculate the day of the week for a given date. The formula is as follows:
    int h = (d + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;
//h is the day of the week (0=Saturday, 1=Sunday, 2=Monday, ..., 6=Friday). The formula takes into account the day of the month (d), the month (m), and the year (y) to calculate the day of the week
//d=day of the month, m=month (3=March, 4=April, ..., 12=December, 13=January, 14=February), y=year (adjusted for January and February), K=year of the century (y % 100), J=zero-based century (actually floor(y/100)). 
//The result h is an integer representing the day of the week (0=Saturday, 1=Sunday, 2=Monday, ..., 6=Friday).
    if (h < 0)
        h += 7;

    string days[] = {
        "Saturday", "Sunday", "Monday",
        "Tuesday", "Wednesday", "Thursday", "Friday"
    };

    return days[h];
}

int main() {
    cout << dayOfWeek(15, 8, 2025);
    return 0;
}