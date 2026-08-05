//The value of ith entry in row number  is nCi . The value can be calculated using following formula.
// nCi = n! / (i! * (n-i)!)   - ith element of nth row
// Cpp program for Pascal's Triangle using Binomial
// Coefficient in O(n^3) and O(1) Space
#include <iostream>
#include <vector>
using namespace std;

int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// Function to print first n rows
// of Pascal's Triangle
vector<vector<int>> printPascal(int n) {
    vector<vector<int>> mat;
  
  	// Iterate through every row and
    // print entries in it
    for (int row = 0; row < n; row++) {

        // Every row has number of
        // integers equal to row
        // number
        vector<int> arr;
        for (int i = 0; i <= row; i++)
            arr.push_back(binomialCoeff(row, i));

        mat.push_back(arr);
    }
    return mat;
}
/*Cases:
    If row == 0 or row == i
        arr[row][i] =1
    Else:
        arr[row][i] = arr[row-1][i-1] + arr[row-1][i]
*/
vector<vector<int>> dynaic_printPascal(int n) {
    
    // An auxiliary array to store 
    // generated pascal triangle values
    vector<vector<int>> mat;

    // Iterate through every line and 
    // print integer(s) in it
    for (int row = 0; row < n; row++) {
      
        // Every line has number of integers 
        // equal to line number
      	vector<int>arr;
        for (int i = 0; i <= row; i++) {
          
        // First and last values in every row are 1
        if (row == i || i == 0)
            arr.push_back(1);
          
        // Other values are sum of values just 
        // above and left of above
        else
            arr.push_back(mat[row - 1][i - 1] + 
                            mat[row - 1][i]);
        }
        mat.push_back(arr);
    }
  return mat;
}
/*
This method is based on approach using Binomial Coefficient. We know that ith entry in a row (n) in Binomial Coefficient is nCi and all rows start with value 1. The idea is to calculate nCi-1  using nCi . It can be calculated in O(1) time.

    nCi = n! / (i! * (n-i)!)   - (Eq - 1)
    nCi-1 = n! / ((i-1)! * (n-i+1)!)  - (Eq - 2)
    On solving Eq- 1 further , we get  nCi = n! / (n-i)! * i * (i-1)!) -  (Eq - 3)
    On solving Eq- 2 further , we get  nCi-1  = n! / ((n- i + 1) * (n-i)! * (i-1)! ) - (Eq - 4)
    Now, divide Eq - 3 by Eq - 4: 
    nCi = nCi-1 * (n-i+1) / i  , So nCi can be calculated from nCi-1 in O(1) time
*/
void exp_printPascal(int n) {
    for (int row = 1; row <= n; row++) {
      
      	// nC0 = 1
        int c = 1; 
        for (int i = 1; i <= row; i++) {

            // The first value in a row is always 1
          	cout << c << " ";
            c = c * (row - i) / i;
        }
        cout << endl;
    }
}
int main() {
  
    int n = 5;
    vector<vector<int>> mat = printPascal(n);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}