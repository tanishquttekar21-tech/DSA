//Given a number n, find the digital root of n. 
//Digital Root of a number is the recursive sum of its digits until we get a single digit number.
#include <iostream>
using namespace std;

int digitalRoot(int n)
{

    // If given number is zero its
    // digit sum will be zero only
    if (n == 0)
        return 0;

    // If result of modulo operation is
    // zero then, the digit sum is 9
    if (n % 9 == 0)
        return 9;

    return (n % 9);
}

int main()
{
    int n = 99999;
    cout << digitalRoot(n);
    return 0;
}