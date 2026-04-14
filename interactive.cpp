#include <iostream>
#include <vector>
#include "prefixSumUtils.h"
using namespace std;

void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "    PREFIX SUM - INTERACTIVE MENU       " << endl;
    cout << "========================================" << endl;
    cout << "1. Create Prefix Sum Array (1D)" << endl;
    cout << "2. Calculate Range Sum (1D)" << endl;
    cout << "3. Calculate Cumulative Values" << endl;
    cout << "4. View Demo Examples" << endl;
    cout << "5. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-5): ";
}

vector<int> inputArray() {
    vector<int> arr;
    int n;
    
    cout << "Enter the size of array: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Invalid size! Using default array [1, 2, 3, 4, 5]" << endl;
        arr = {1, 2, 3, 4, 5};
        return arr;
    }
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    return arr;
}

void printArray(vector<int>& arr, string name) {
    cout << name << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void option1_CreatePrefixSum() {
    cout << "\n=== Option 1: Create Prefix Sum Array ===" << endl;
    
    vector<int> arr = inputArray();
    vector<int> prefix(arr.size());
    
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    printArray(arr, "Original Array");
    printArray(prefix, "Prefix Sum Array");
}

void option2_CalculateRangeSum() {
    cout << "\n=== Option 2: Calculate Range Sum ===" << endl;
    
    vector<int> arr = inputArray();
    
    // Create prefix sum array
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    printArray(arr, "Original Array");
    printArray(prefix, "Prefix Sum Array");
    
    int left, right;
    cout << "\nEnter left index: ";
    cin >> left;
    cout << "Enter right index: ";
    cin >> right;
    
    int rangeSum = getRangeSum(prefix, left, right);
    
    if (rangeSum == 0 && (left < 0 || right >= arr.size() || left > right)) {
        cout << "Invalid range indices!" << endl;
    } else {
        cout << "Sum from index " << left << " to " << right << " = " << rangeSum << endl;
    }
}

void option3_CumulativeValues() {
    cout << "\n=== Option 3: View Cumulative Values ===" << endl;
    
    vector<int> arr = inputArray();
    
    cout << "\nCumulative Values (Running Total):" << endl;
    cout << "Index | Value | Cumulative Sum" << endl;
    cout << "------|-------|----------------" << endl;
    
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        printf("%5d | %5d | %6d\n", i, arr[i], sum);
    }
}

void option4_DemoExamples() {
    cout << "\n=== Option 4: Demo Examples ===" << endl;
    
    cout << "\n--- Example 1: Simple Array ---" << endl;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> prefix1(arr1.size());
    prefix1[0] = arr1[0];
    for (int i = 1; i < arr1.size(); i++) {
        prefix1[i] = prefix1[i - 1] + arr1[i];
    }
    printArray(arr1, "Original");
    printArray(prefix1, "Prefix Sum");
    cout << "Range sum (index 1-3): " << getRangeSum(prefix1, 1, 3) << endl;
    
    cout << "\n--- Example 2: Stock Prices ---" << endl;
    vector<int> prices = {100, 110, 120, 130, 115};
    vector<int> prefixPrices(prices.size());
    prefixPrices[0] = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        prefixPrices[i] = prefixPrices[i - 1] + prices[i];
    }
    printArray(prices, "Stock Prices");
    printArray(prefixPrices, "Cumulative Prices");
    cout << "Total price from day 1-3: $" << getRangeSum(prefixPrices, 1, 3) << endl;
    
    cout << "\n--- Example 3: Temperature Data ---" << endl;
    vector<int> temps = {15, 18, 22, 25, 20, 16};
    vector<int> prefixTemps(temps.size());
    prefixTemps[0] = temps[0];
    for (int i = 1; i < temps.size(); i++) {
        prefixTemps[i] = prefixTemps[i - 1] + temps[i];
    }
    printArray(temps, "Daily Temperatures");
    int avgTemp = getRangeSum(prefixTemps, 0, 5) / 6;
    cout << "Average temperature: " << avgTemp << "°C" << endl;
}

int main() {
    int choice;
    bool running = true;
    
    cout << "\nWelcome to Prefix Sum Calculator!" << endl;
    
    while (running) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                option1_CreatePrefixSum();
                break;
            case 2:
                option2_CalculateRangeSum();
                break;
            case 3:
                option3_CumulativeValues();
                break;
            case 4:
                option4_DemoExamples();
                break;
            case 5:
                cout << "\nThank you for using Prefix Sum Calculator! Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
    }
    
    return 0;
}
