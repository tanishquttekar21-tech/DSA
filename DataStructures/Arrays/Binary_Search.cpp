#include <iostream>
#include <vector>
using namespace std;

int iterative_binarySearch(vector<int> &arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}
int reccursive_binarySearch(vector<int> &arr, int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return reccursive_binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return reccursive_binarySearch(arr, mid + 1, high, x);
    }
  return -1;
}

int main() {
    vector<int> arr = { 2, 3, 4, 10, 40 };
    int x = 10;
    int result = iterative_binarySearch(arr, x);
    int result2 = reccursive_binarySearch(arr, 0, arr.size() - 1, x);
    
    if(result == -1) cout << "Element is not present in array";
    else cout << "Element is present at index " << result;
    return 0;
}