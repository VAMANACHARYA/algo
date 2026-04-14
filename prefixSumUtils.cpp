#include "prefixSumUtils.h"

// Function to get sum between two indexes in the prefix sum array
// Returns the sum of original array elements from index left to right (inclusive)
int getRangeSum(vector<int>& prefix, int left, int right) {
    if (left < 0 || right >= prefix.size() || left > right) {
        return 0; // Invalid range
    }
    
    // If left is 0, sum is just prefix[right]
    if (left == 0) {
        return prefix[right];
    }
    
    // Otherwise, sum from left to right = prefix[right] - prefix[left-1]
    return prefix[right] - prefix[left - 1];
}
