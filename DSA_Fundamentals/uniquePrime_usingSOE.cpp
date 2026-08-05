/*The idea in the SPF approach is to precompute the smallest prime factor (SPF) for every number up to n using a modified sieve.
 Once SPF is ready, we can efficiently find the unique prime factors of any number by repeatedly dividing it by its SPF.
  This makes each factorization run in O(log n) time.

  Step by step approach:

    Precompute the smallest prime factor (spf) for every number up to n.
    Create an spf[] array and initialize spf[i] = i.
    Use the Sieve of Eratosthenes to fill the smallest prime factor for each number.
    To find the unique prime factors of n, repeatedly use spf[n] and store each distinct factor.
    Divide n by the current prime factor until it is no longer divisible.
    Continue until n becomes 1.

*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> computeSPF(int N) {
    //making an array to store the smallest prime factor for every number
    vector<int>spf(N+1);
    for (int i = 0; i <= N; ++i) {
        spf[i] = i;
    }

    for (int i = 2; i * i <= N; ++i) {
        // i is prime
        if (spf[i] == i) { 
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

vector<int> primeFac(int n) {
    vector<int>spf = computeSPF(n);
    // Using a set to store unique prime factors
    set<int> uniqueFactors;
    // Extracting unique prime factors using the spf array
    while (n > 1) {
        uniqueFactors.insert(spf[n]);
        // Divide n by its smallest prime factor to continue factorization
        n /= spf[n];
    }
    // Convert the set to a vector for the result
    return vector<int>(uniqueFactors.begin(), uniqueFactors.end());
}

int main() {
    
    int n = 100;
    vector<int> result = primeFac(n);
    for (int factor : result) {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}