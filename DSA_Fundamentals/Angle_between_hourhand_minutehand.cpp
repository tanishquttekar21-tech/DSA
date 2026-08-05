/*The minute hand moves 6° per minute, while the hour hand moves 0.5° per minute.
 Thus, the hour hand's angle is calculated as hrAngle = 30 × H + 0.5 × M, and the minute hand's angle as minAngle = 6 × M.
  The difference between the two angles is diff = |hrAngle - minAngle|.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Utility function to return the minimum of two double values
double getMin(double x, double y) {
    return (x < y) ? x : y;
}

// Function to calculate the minimum angle between 
// hour and minute hands
double getAngle(string s) {
    // Extract hours and minutes from "HH:MM"
    //stoi is a function from the <string> library that converts a string to an integer.
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    // Convert 24-hour time to 12-hour format
    h = h % 12;

    // Hour hand moves 0.5 degrees per minute 
    // (30 degrees per hour)
    double hrAngle = 0.5 * (h * 60 + m);

    // Minute hand moves 6 degrees per minute
    double minAngle = 6 * m;

    // Find the absolute difference between the two angles
    //fabs is a function from the <cmath> library that returns the absolute value of a floating-point number.
    double angle = fabs(hrAngle - minAngle);

    // Return the smaller angle of the two possible angles
    return getMin(360.0 - angle, angle);
}

int main() {
    string s = "06:00" ;

    cout << fixed << setprecision(3);
    //setprecision is a function from the <iomanip> library that sets the decimal precision for floating-point output.
    cout << getAngle(s) << endl;

    return 0;
}