#include "prefixSum2D.h"
#include <iostream>

// Create 2D prefix sum matrix
// prefix[i][j] = sum of all elements from (0,0) to (i,j)
Matrix createPrefix2D(Matrix& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return matrix;
    }
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    Matrix prefix(rows, vector<int>(cols, 0));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            prefix[i][j] = matrix[i][j];
            
            // Add sum from left
            if (j > 0) {
                prefix[i][j] += prefix[i][j - 1];
            }
            
            // Add sum from top
            if (i > 0) {
                prefix[i][j] += prefix[i - 1][j];
            }
            
            // Subtract overlap (counted twice)
            if (i > 0 && j > 0) {
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    
    return prefix;
}

// Get sum of rectangle from (r1, c1) to (r2, c2) inclusive
int getRectangleSum(Matrix& prefix, int r1, int c1, int r2, int c2) {
    if (r1 < 0 || c1 < 0 || r2 >= prefix.size() || 
        c2 >= prefix[0].size() || r1 > r2 || c1 > c2) {
        return 0; // Invalid coordinates
    }
    
    int sum = prefix[r2][c2];
    
    if (r1 > 0) {
        sum -= prefix[r1 - 1][c2];
    }
    
    if (c1 > 0) {
        sum -= prefix[r2][c1 - 1];
    }
    
    if (r1 > 0 && c1 > 0) {
        sum += prefix[r1 - 1][c1 - 1];
    }
    
    return sum;
}

// Print 2D matrix
void printMatrix(Matrix& matrix, string name) {
    cout << name << ":" << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            printf("%4d ", val);
        }
        cout << endl;
    }
    cout << endl;
}
