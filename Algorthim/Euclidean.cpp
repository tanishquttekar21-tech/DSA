#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
//This is an optimized version of the above function
int optimised_gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    cout << "To get gcd Enter two numbers: ";
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}