// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


// PART A: Transpose Matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:" << endl;

    displayMatrix(transpose, cols, rows);
}


// PART B: Add Two Matrices
void addMatrices(int matrixA[10][10], int matrixB[10][10],
                 int rows, int cols)
{
    int result[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nSum of Matrices:" << endl;

    displayMatrix(result, rows, cols);
}


// PART C: Multiply Two Matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10],
                      int rowsA, int colsA, int rowsB, int colsB)
{
    int result[10][10] = {0};


    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }


    cout << "\nProduct of Matrices:" << endl;

    displayMatrix(result, rowsA, colsB);
}


// Function to input matrix values
void inputMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}


int main()
{
    int matrixA[10][10];
    int matrixB[10][10];

    int rows, cols;


    // PART A
    cout << "========== PART A: TRANSPOSE MATRIX ==========" << endl;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;


    inputMatrix(matrixA, rows, cols);


    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrixA, rows, cols);


    transposeMatrix(matrixA, rows, cols);



    // PART B

    cout << "\n========== PART B: ADD MATRICES ==========" << endl;


    cout << "Enter rows for addition: ";
    cin >> rows;

    cout << "Enter columns for addition: ";
    cin >> cols;


    cout << "\nEnter Matrix A:" << endl;
    inputMatrix(matrixA, rows, cols);


    cout << "\nEnter Matrix B:" << endl;
    inputMatrix(matrixB, rows, cols);


    addMatrices(matrixA, matrixB, rows, cols);



    // PART C

    cout << "\n========== PART C: MULTIPLY MATRICES ==========" << endl;


    int rowsA, colsA, rowsB, colsB;


    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;

    cout << "Enter columns of Matrix A: ";
    cin >> colsA;


    cout << "\nEnter Matrix A:" << endl;
    inputMatrix(matrixA, rowsA, colsA);



    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;

    cout << "Enter columns of Matrix B: ";
    cin >> colsB;


    if (colsA != rowsB)
    {
        cout << "Error: Matrix multiplication not possible." << endl;
    }
    else
    {
        cout << "\nEnter Matrix B:" << endl;

        inputMatrix(matrixB, rowsB, colsB);

        multiplyMatrices(matrixA, matrixB,
                         rowsA, colsA, rowsB, colsB);
    }


    return 0;
}