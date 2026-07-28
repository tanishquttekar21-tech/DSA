#include <iostream>
#include <algorithm>
using namespace std;

int lcm(int a, int b) {
    
    // larger value
    int g = max(a, b);
    
    // Smaller value
    int s = min(a, b);
    
    for (int i = g; i <= a * b; i += g) {
        if (i % s == 0)
            return i;
    }
}
/*But we can also solve this problem using the formula: LCM(a, b) = (a * b) / GCD(a, b). 
This is a more efficient approach as it avoids the need for iteration and directly computes the LCM using the GCD.*/
// function for gcd
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int exp_lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int a = 10, b = 5;
    cout << lcm(a, b);
    cout << exp_lcm(a, b);
    return 0;
}

