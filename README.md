# Prefix Sum Array - Complete Implementation Guide

## Overview
This project provides a comprehensive implementation of **Prefix Sum Arrays** in C++, with both 1D and 2D solutions, interactive menu system, and complete unit tests.

A **prefix sum array** is an auxiliary array where each element at index `i` contains the sum of all elements from index `0` to `i` in the original array. This data structure enables efficient range sum queries.

## Table of Contents
1. [Features](#features)
2. [Project Structure](#project-structure)
3. [Installation & Compilation](#installation--compilation)
4. [Usage Guide](#usage-guide)
5. [Algorithm Explanation](#algorithm-explanation)
6. [Complexity Analysis](#complexity-analysis)
7. [Real-World Applications](#real-world-applications)
8. [Examples](#examples)
9. [Testing](#testing)

---

## Features

✓ **1D Prefix Sum** - Classic single-dimensional prefix sum array  
✓ **2D Prefix Sum** - For matrix range sum queries  
✓ **Interactive Menu** - User-friendly interface with multiple options  
✓ **Unit Tests** - Comprehensive test suite with 12+ test cases  
✓ **Demo Examples** - Real-world scenario demonstrations  
✓ **Modular Code** - Separated header files and implementations  
✓ **Edge Case Handling** - Negative numbers, invalid ranges, boundary conditions  

---

## Project Structure

```
algo/
├── prefix_sum.cpp          # Main 1D prefix sum demonstration
├── prefixSumUtils.h        # Header file for 1D utilities
├── prefixSumUtils.cpp      # Implementation of 1D functions
├── prefixSum2D.h           # Header file for 2D utilities
├── prefixSum2D.cpp         # Implementation of 2D functions
├── interactive.cpp         # Interactive menu-driven program
├── test.cpp                # Unit test suite
├── Makefile                # Build configuration
└── README.md               # This file
```

---

## Installation & Compilation

### Prerequisites
- GCC compiler (g++)
- Linux/Mac terminal or WSL

### Compile Individual Programs

**1. Basic Demo:**
```bash
g++ -o prefix_sum prefix_sum.cpp prefixSumUtils.cpp
./prefix_sum
```

**2. Interactive Program:**
```bash
g++ -o interactive interactive.cpp prefixSumUtils.cpp prefixSum2D.cpp
./interactive
```

**3. Run Unit Tests:**
```bash
g++ -o test test.cpp prefixSumUtils.cpp prefixSum2D.cpp
./test
```

### Using Makefile (Easy Way)

```bash
make interactive    # Compile interactive program
make test          # Compile and run tests
make demo          # Run basic demo
make clean         # Remove compiled files
make all           # Compile everything
```

---

## Usage Guide

### Option 1: Basic Demo
```bash
./prefix_sum
```
Shows three examples with explanations.

### Option 2: Interactive Menu
```bash
./interactive
```

**Menu Options:**
1. **Create Prefix Sum Array (1D)**
   - Input your own array
   - View the prefix sum result

2. **Calculate Range Sum (1D)**
   - Enter an array
   - Query sum between two indices

3. **Calculate Cumulative Values**
   - Display table of running totals

4. **View Demo Examples**
   - Stock prices analysis
   - Temperature data
   - Simple arrays

5. **Exit**

### Option 3: Run Tests
```bash
./test
```
Executes all 12+ unit tests and shows results.

---

## Algorithm Explanation

### 1D Prefix Sum

**Building the Prefix Sum Array:**
```cpp
prefix[0] = arr[0]
for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + arr[i]
}
```

**Example:**
```
Original:  [1, 2, 3, 4, 5]
Prefix:    [1, 3, 6, 10, 15]
```

**Range Sum Query:**
```cpp
// Sum from index left to right (inclusive)
sum = prefix[right] - (left > 0 ? prefix[left-1] : 0)
```

### 2D Prefix Sum

**Building the 2D Prefix Sum:**
```cpp
prefix[i][j] = matrix[i][j] 
              + prefix[i-1][j]      // Top
              + prefix[i][j-1]      // Left
              - prefix[i-1][j-1]    // Overlap (subtract counted twice)
```

**Rectangle Sum Query (r1,c1) to (r2,c2):**
```cpp
sum = prefix[r2][c2]
    - prefix[r1-1][c2]      // Exclude top part
    - prefix[r2][c1-1]      // Exclude left part
    + prefix[r1-1][c1-1]    // Add back overlap
```

---

## Complexity Analysis

| Operation | 1D | 2D |
|-----------|----|----|
| **Build Prefix Sum** | O(n) | O(n×m) |
| **Range Query** | O(1) | O(1) |
| **Space Complexity** | O(n) | O(n×m) |

### Why Prefix Sum is Useful?
- **Without prefix sum:** Each range query takes O(n) time
- **With prefix sum:** Each range query takes O(1) time
- For multiple queries, prefix sum is significantly faster

---

## Real-World Applications

### 1. **Stock Price Analysis**
Calculate total earnings over a period of days in constant time.

### 2. **2D Image Processing**
Quick rectangle sum queries for image filtering and analysis.

### 3. **Query Statistics**
Rapid range queries on datasets (temperature, sales, website hits).

### 4. **Competitive Programming**
Solve range sum problems efficiently in contests.

### 5. **Data Analytics**
Cumulative statistics and trends analysis.

---

## Examples

### Example 1: Simple Array
```cpp
Original:   [1, 2, 3, 4, 5]
Prefix:     [1, 3, 6, 10, 15]

Query: Sum from index 1 to 3
Result: prefix[3] - prefix[0] = 10 - 1 = 9 ✓ (2+3+4=9)
```

### Example 2: Stock Prices
```cpp
Stock Prices:     [100, 110, 120, 130, 115]
Cumulative Prices: [100, 210, 330, 460, 575]

Query: Total price from day 1 to 3
Result: 110 + 120 + 130 = 360 ✓
```

### Example 3: 2D Matrix
```
Matrix:
   1   2   3
   4   5   6
   7   8   9

Prefix Sum:
   1   3   6
   5  12  21
  12  27  45

Query: Sum of rectangle (0,0) to (1,1)
Result: 1+2+4+5 = 12 ✓
```

---

## Testing

### Run Unit Tests
```bash
./test
```

### Test Coverage
- ✓ 1D basic arrays
- ✓ 1D range queries
- ✓ 1D full range
- ✓ Single element arrays
- ✓ Negative numbers
- ✓ Invalid ranges
- ✓ 2D basic matrix
- ✓ 2D rectangle queries
- ✓ 2D single cell
- ✓ 2D full matrix
- ✓ 2D single row
- ✓ 2D single column

---

## Function Reference

### 1D Functions (prefixSumUtils.cpp)
```cpp
// Get sum between two indices
int getRangeSum(vector<int>& prefix, int left, int right);
```

### 2D Functions (prefixSum2D.cpp)
```cpp
// Create 2D prefix sum matrix
Matrix createPrefix2D(Matrix& matrix);

// Get sum of rectangle
int getRectangleSum(Matrix& prefix, int r1, int c1, int r2, int c2);

// Print 2D matrix
void printMatrix(Matrix& matrix, string name);
```

---

## Key Insights

1. **Trade-off:** O(n) preprocessing time for O(1) query time
2. **Immutability:** Once prefix sum is built, original array shouldn't change
3. **Memory:** Requires extra O(n) space but worth it for multiple queries
4. **Extensibility:** Can be extended to 3D, 4D, or higher dimensions
5. **Difference Array:** Opposite of prefix sum - useful for range updates

---

## Limitations & Extensions

### Current Limitations
- Assumes integer values (can be templated for other types)
- Array elements don't change after preprocessing

### Possible Extensions
- **Templates:** Support `long long`, `double`, custom types
- **Difference Array:** For range update operations
- **Lazy Propagation:** Combined with segment trees for dynamic ranges
- **Persistent Segment Trees:** For version control of prefix sums
- **3D Prefix Sum:** For volumetric data analysis

---

## Compilation Tips

**Optimize compilation:**
```bash
g++ -O2 -Wall -Wextra -o program program.cpp utils.cpp
```

**Debug mode:**
```bash
g++ -g -O0 -Wall -Wextra -o program program.cpp utils.cpp
```

---

## Contributing & Improvements

Feel free to:
- Add more test cases
- Implement templated versions
- Create a difference array module
- Add 3D prefix sum
- Optimize for specific data types

---

## License
This project is open source and available for educational purposes.

---

## Author Notes

- **Time Complexity:** Never underestimate the power of preprocessing!
- **Use Cases:** Many real-world problems benefit from prefix sum optimization
- **Interview Tip:** Prefix sum is a classic data structure problem in coding interviews
- **Learning Value:** Understanding prefix sum helps with 2D array problems

---

## Quick Start Checklist

- [ ] Clone the repository
- [ ] Run `./interactive` to see the menu
- [ ] Enter your own array to test
- [ ] Run `./test` to verify functionality
- [ ] Study the source code
- [ ] Try implementing for 3D arrays

---

**For questions or issues, refer to the source code comments!**

Happy Learning! 🚀