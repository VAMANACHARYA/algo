#include <iostream>
#include <vector>
#include "prefixSumUtils.h"
#include "prefixSum2D.h"
using namespace std;

// Test utilities
int testsRun = 0;
int testsPassed = 0;

void testResult(string testName, bool passed) {
    testsRun++;
    if (passed) {
        testsPassed++;
        cout << "✓ PASS: " << testName << endl;
    } else {
        cout << "✗ FAIL: " << testName << endl;
    }
}

// 1D Prefix Sum Tests
void test1D_BasicArray() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    vector<int> expected = {1, 3, 6, 10, 15};
    testResult("1D: Basic array [1,2,3,4,5]", prefix == expected);
}

void test1D_RangeSum() {
    vector<int> arr = {2, 4, 6, 8, 10};
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    int sum = getRangeSum(prefix, 1, 3); // 4 + 6 + 8 = 18
    testResult("1D: Range sum (1,3) = 18", sum == 18);
}

void test1D_FullRange() {
    vector<int> arr = {1, 1, 1, 1, 1};
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    int sum = getRangeSum(prefix, 0, 4); // All elements = 5
    testResult("1D: Full range sum = 5", sum == 5);
}

void test1D_SingleElement() {
    vector<int> arr = {42};
    vector<int> prefix = {42};
    
    int sum = getRangeSum(prefix, 0, 0); // Single element
    testResult("1D: Single element = 42", sum == 42);
}

void test1D_NegativeNumbers() {
    vector<int> arr = {-1, 2, -3, 4, -5};
    vector<int> prefix(arr.size());
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    int sum = getRangeSum(prefix, 0, 4); // -1+2-3+4-5 = -3
    testResult("1D: Negative numbers = -3", sum == -3);
}

void test1D_InvalidRange() {
    vector<int> prefix = {1, 3, 6, 10};
    
    int sum = getRangeSum(prefix, 5, 10); // Out of bounds
    testResult("1D: Invalid range returns 0", sum == 0);
}

// 2D Prefix Sum Tests
void test2D_BasicMatrix() {
    Matrix matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    Matrix prefix = createPrefix2D(matrix);
    Matrix expected = {
        {1, 3, 6},
        {5, 12, 21},
        {12, 27, 45}
    };
    
    testResult("2D: Basic 3x3 matrix", prefix == expected);
}

void test2D_RectangleSum() {
    Matrix matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    Matrix prefix = createPrefix2D(matrix);
    int sum = getRectangleSum(prefix, 0, 0, 1, 1); // 1+2+4+5 = 12
    testResult("2D: Rectangle sum (0,0) to (1,1) = 12", sum == 12);
}

void test2D_SingleCell() {
    Matrix matrix = {
        {5, 10},
        {15, 20}
    };
    
    Matrix prefix = createPrefix2D(matrix);
    int sum = getRectangleSum(prefix, 1, 1, 1, 1); // Just cell [1][1] = 20
    testResult("2D: Single cell [1][1] = 20", sum == 20);
}

void test2D_FullMatrix() {
    Matrix matrix = {
        {1, 1},
        {1, 1}
    };
    
    Matrix prefix = createPrefix2D(matrix);
    int sum = getRectangleSum(prefix, 0, 0, 1, 1); // All elements = 4
    testResult("2D: Full matrix sum = 4", sum == 4);
}

void test2D_SingleRow() {
    Matrix matrix = {
        {2, 4, 6, 8}
    };
    
    Matrix prefix = createPrefix2D(matrix);
    int sum = getRectangleSum(prefix, 0, 1, 0, 3); // 4+6+8 = 18
    testResult("2D: Single row range = 18", sum == 18);
}

void test2D_SingleColumn() {
    Matrix matrix = {
        {1},
        {2},
        {3},
        {4}
    };
    
    Matrix prefix = createPrefix2D(matrix);
    int sum = getRectangleSum(prefix, 1, 0, 3, 0); // 2+3+4 = 9
    testResult("2D: Single column range = 9", sum == 9);
}

// Run all tests
void runAllTests() {
    cout << "\n========================================" << endl;
    cout << "       RUNNING UNIT TESTS" << endl;
    cout << "========================================\n" << endl;
    
    cout << "--- 1D Prefix Sum Tests ---" << endl;
    test1D_BasicArray();
    test1D_RangeSum();
    test1D_FullRange();
    test1D_SingleElement();
    test1D_NegativeNumbers();
    test1D_InvalidRange();
    
    cout << "\n--- 2D Prefix Sum Tests ---" << endl;
    test2D_BasicMatrix();
    test2D_RectangleSum();
    test2D_SingleCell();
    test2D_FullMatrix();
    test2D_SingleRow();
    test2D_SingleColumn();
    
    cout << "\n========================================" << endl;
    cout << "RESULTS: " << testsPassed << "/" << testsRun << " tests passed" << endl;
    cout << "========================================" << endl;
    
    if (testsPassed == testsRun) {
        cout << "✓ All tests passed!" << endl;
    } else {
        cout << "✗ Some tests failed!" << endl;
    }
}

int main() {
    runAllTests();
    return 0;
}
