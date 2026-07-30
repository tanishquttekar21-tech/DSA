/*Given two integer arrays a[] and b[] containing two integers each representing the numerator and denominator of a fraction respectively. 
The task is to find the sum of the two fractions and return the numerator and denominator of the result. */
#include<bits/stdc++.h>
using namespace std;

// Function to find gcd of a and b
int gcd(int n1, int n2)
{
    if (n1 == 0)
        return n2;
    return gcd(n2%n1, n1);
}

//Function to add two fractions
vector<int> addFraction(vector<int> a, vector<int>b)
{
    vector<int> ans; 
    // Finding gcd of den1 and den2
    int den = gcd(a[1],b[1]);

    // Denominator of final fraction obtained
    // finding LCM of den1 and den2
    // LCM * GCD = a * b 
    den = (a[1]*b[1]) / den;

    // Changing the fractions to have same denominator
    // Numerator of the final fraction obtained
    int num = (a[0])*(den/a[1]) + (b[0])*(den/b[1]);

    // finding the common factor of numerator and denominator
    int common_factor = gcd(num,den);

    // Converting the result into simpler 
    // fraction by dividing them with common factor 
    den = den/common_factor;
    num = num/common_factor;
    ans.push_back(num); 
    ans.push_back(den); 
    return ans;
    
}

int main()
{
    vector<int> a = {1,2};
    vector<int> b = {3,2};
    vector<int> ans = addFraction(a, b); 
    cout<<ans[0]<<", "<<ans[1];
    return 0;
}