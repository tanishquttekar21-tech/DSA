/*A number is a perfect number if it is equal to the sum of its proper divisors, that is, the sum of its positive divisors excluding the number itself.
 Find whether a given positive integer n is perfect or not. */
#include <iostream>
using namespace std;

// Function to check if a number is perfect or not
bool isPerfect(int n){
    int sum = 1; // 1 is a proper divisor of every number
    // Loop to find all divisors of n  
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            if(i*i != n) // Check if divisors are equal
                sum += i + n/i; // Add both divisors
            else
                sum += i; // Add only one divisor if they are equal
        }
    }
    if(sum == n && n != 1) // Check if sum of divisors is equal to n and n is not 1
        return true;
    else
        return false;
}
/*logic behind the code is that we did not need to check for all the numbers 
from 1 to n-1 as we can find the divisors of a number by checking only till its square root.*/
int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if(isPerfect(n))
        cout << n << " is a perfect number." << endl;
    else
        cout << n << " is not a perfect number." << endl;
    return 0;
}
