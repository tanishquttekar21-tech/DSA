#include <iostream>
using namespace std;

// Function to calculate factorial
long long fact(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// Function to calculate nPr
long long nPr(int n, int r)
{
    if (r > n)
        return 0;

    return fact(n) / fact(n - r);
}
//expected approach to calculate nPr without calculating factorials directly,
// which can be more efficient and avoids potential overflow issues for large n and r.
long long exp_nPr(int n, int r)
{
    if (r > n)
        return 0;

    long long ans = 1;

    // Compute n × (n-1) × ... × (n-r+1)
    for (int i = 0; i < r; i++)
        ans *= (n - i);

    return ans;
}

int main()
{
    int n = 5;
    int r = 2;

    cout << exp_nPr(n, r) << endl;

    return 0;
}