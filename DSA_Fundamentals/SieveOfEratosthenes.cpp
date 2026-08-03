//The Sieve of Eratosthenes efficiently finds all primes up to n by repeatedly marking multiples of each prime as non-prime,
// starting from 2. This avoids redundant checks and quickly filters out all composite numbers.
//Initialize a Boolean array prime[0..n] and set all entries to true,
// except for 0 and 1 (which are not primes).
#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
    
    // creation of boolean array
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            // marking as false the multiples of p
            // starting from p*p, as all smaller multiples of p will have already been marked by smaller primes
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    vector<int> res;
    for (int p = 2; p <= n; p++){
        if (prime[p]){ 
            res.push_back(p);
        }
    }
    return res;
}

int main(){
    int n = 35;
    vector<int> res = sieve(n);
    for(auto ele : res){
        cout << ele << ' ';
    }
    return 0;
}