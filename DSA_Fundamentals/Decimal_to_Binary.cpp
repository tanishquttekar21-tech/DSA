#include<iostream>
#include<algorithm>
using namespace std;



string decimalToBinary(int n){
    string binary = "";
    while(n>0){
        int bit = n%2;
        //ASCII value of '0' is 48 and '1' is 49, so we can add '0' to the bit to get the corresponding character
        binary.push_back('0'+bit);
        n /= 2; 
    }
    reverse(binary.begin(), binary.end());
    return binary;
}
//Using bitwise operators, we can extract binary digits by checking the least significant bit (n & 1) and then right-shifting the number (n >> 1) to process the next bit.
//This method is faster than arithmetic division and modulo, as bitwise operations are more efficient at the hardware level.
string decimalToBinaryBitwise(int n){
    string binary = "";
    while(n>0){
        int bit = n & 1; //Extract the least significant bit
        binary.push_back('0'+bit);
        n >>= 1; //Right shift to process the next bit it removes last bit from the number and divides it by 2
    }
    reverse(binary.begin(), binary.end());
    return binary;
}
int main(){
    int n;
    cout<<"Enter a decimal number: ";
    cin>>n;
    cout<<"Binary representation of "<<n<<" is: "<<decimalToBinary(n)<<endl;
    cout<<"Binary representation of "<<n<<" using bitwise operators is: "<<decimalToBinaryBitwise(n)<<endl;
    return 0;
}