//Given two positive numbers x and y, check if y is a power of x or not.
/*The idea is to increase the value very quickly using repeated squaring instead of normal multiplication, 
allowing it to reach close to y in fewer steps.
 If the value becomes equal to y, it returns true. 
If it goes beyond y, a binary search is used to check different possible powers of x and find if any of them exactly equals y.
*/
#include <iostream>
#include <cmath>
using namespace std;

bool isPower(int x, int y) {
    
    // The only power of 1 is 1 itself
    if (x == 1)
        return (y == 1);

    // If y is 1, then x^0 = 1
    if (y == 1)
        return true;

    // Repeatedly compute power of x using squaring
    int pow = x, i = 1;
    while (pow < y) {
        pow *= pow;
        
        // track exponent growth
        i *= 2;
    }
    //Now pow is greater than or equal to y, check if it is equal
    if (pow == y)
        return true;

    // Apply binary search to find correct power
    int low = x, high = pow;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Estimate exponent using logarithm
        int exponent = (int)(log(mid) / log(x));
        int result = (int)powl(x, exponent);

        if (result == y)
            return true;

        // Move search space
        if (result < y)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // If no power matches
    return false;
}
bool exp_isPower(int x, int y)
{
    // Edge case: 1^k = 1 only
    if (x == 1)
        return y == 1;

    // Edge case: x^0 = 1
    if (y == 1)
        return true;

    // Compute logarithm
    double res = log(y) / log(x);
    
    // Compare with rounded value using a small 
    // tolerance to avoid floating point errors
    return fabs(res - round(res)) < 1e-10;
    //case x=2,y=8 res=2.999.. hence round(res)=3 and fabs(res-round(res))=0<1e-10 so return true
}

int main() {
    
    cout << boolalpha;
    cout << isPower(10, 1) << endl;
    cout << exp_isPower(2, 8) << endl;
    return 0;
}