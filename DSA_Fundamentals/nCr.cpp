#include <iostream>
#include <cmath>
using namespace std;

int nCr(int n, int r) {
  
    // No valid combinations if r is greater than n
    if (r > n) 
        return 0;
  
    // Base case: only one way to choose 0 or all elements
    if (r == 0 || r == n) 
        return 1;
  
    // include or exclude current element
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}
int exp_nCr(int n, int r){
    
    double sum = 1;

    // Calculate the value of n choose
    // r using the binomial coefficient formula
    for (int i = 1; i <= r; i++){
        
        sum = sum * (n - r + i) / i;
    }
    return (int)sum;
}
// Calculates the binomial coefficient nCr using logarithmic formula
int log_nCr(int n, int r) {
    // Invalid case
    if (r > n) return 0;  
    // Base cases
    if (r == 0 || n == r) return 1;    

    double res = 0;
    for (int i = 0; i < r; i++) {
        // log(n!) - log(r!) - log((n-r)!)
        res += log(n - i) - log(i + 1);  
    }

    return (int)round(exp(res));
}


// Driver Code
int main() {
    int n = 5;
    int r = 2;
    cout << exp_nCr(n, r);
    return 0;
}