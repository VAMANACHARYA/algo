#include <iostream>
#include <vector>
#include "prefixSumUtils.h"
using namespace std;

// Function to create prefix sum array
vector<int> createPrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    
    prefix[0] = arr[0];
    
    for (int i = 1; i < n; i++) {
        prefix[i] = arr[i] + prefix[i - 1];
    }
    
    return prefix;
}

// Function to print array
void printArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example 1: Simple array
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    printArray(arr1);
    
    vector<int> prefix1 = createPrefixSum(arr1);
    cout << "Prefix sum array: ";
    printArray(prefix1);
    
    cout << endl;
    
    // Example 2: Another array
    vector<int> arr2 = {5, 10, 15, 20};
    cout << "Original array: ";
    printArray(arr2);
    
    vector<int> prefix2 = createPrefixSum(arr2);
    cout << "Prefix sum array: ";
    printArray(prefix2);
    
    cout << endl;
    
    // Example 3: Using prefix sum for range query
    vector<int> arr3 = {2, 4, 6, 8, 10};
    cout << "Original array: ";
    printArray(arr3);
    
    vector<int> prefix3 = createPrefixSum(arr3);
    cout << "Prefix sum array: ";
    printArray(prefix3);
    
    // Sum from index 1 to 3 (elements 4, 6, 8) using the utility function
    int left = 1, right = 3;
    int rangeSum = getRangeSum(prefix3, left, right);
    cout << "Sum of elements from index " << left << " to " << right << ": " << rangeSum << endl;
    
    return 0;
}
