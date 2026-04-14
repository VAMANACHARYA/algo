# Test Cases for Prefix Sum Functions

#include <iostream>
#include <vector>
#include <cassert>

// Function to calculate the prefix sum
std::vector<int> prefixSum(const std::vector<int>& arr) {
    std::vector<int> result(arr.size());
    result[0] = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        result[i] = result[i - 1] + arr[i];
    }
    return result;
}

// Test function to validate prefix sum
void testPrefixSum() {
    // Test 1: Empty array
    std::vector<int> emptyArray;
    assert(prefixSum(emptyArray).empty());

    // Test 2: Single element
    std::vector<int> singleElementArray = {5};
    assert(prefixSum(singleElementArray) == std::vector<int>{5});

    // Test 3: Multiple elements
    std::vector<int> multipleElements = {1, 2, 3, 4};
    assert(prefixSum(multipleElements) == std::vector<int>{1, 3, 6, 10});

    // Test 4: Negative numbers
    std::vector<int> negativeNumbers = {-1, -2, -3, -4};
    assert(prefixSum(negativeNumbers) == std::vector<int>{-1, -3, -6, -10});

    // Test 5: Mixed numbers
    std::vector<int> mixedNumbers = {1, -1, 2, -2};
    assert(prefixSum(mixedNumbers) == std::vector<int>{1, 0, 2, 0});

    // Test 6: Range queries
    std::vector<int> rangeQueryArray = {1, 2, 3, 4, 5};
    std::vector<int> prefix = prefixSum(rangeQueryArray);
    assert(prefix[4] == 15); // Total sum
    assert(prefix[1] == 3);   // Sum of first two elements
    assert(prefix[2] == 6);   // Sum of first three elements

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testPrefixSum();
    return 0;
}