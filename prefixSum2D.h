#ifndef PREFIX_SUM_2D_H
#define PREFIX_SUM_2D_H

#include <vector>
#include <string>
using namespace std;

typedef vector<vector<int>> Matrix;

// Function to create 2D prefix sum matrix
Matrix createPrefix2D(Matrix& matrix);

// Function to get sum in a rectangle from (r1, c1) to (r2, c2)
int getRectangleSum(Matrix& prefix, int r1, int c1, int r2, int c2);

// Function to print a 2D matrix
void printMatrix(Matrix& matrix, string name);

#endif
