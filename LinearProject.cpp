#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void createMatrix(int **arr, int rows, int cols);
void ID_Matrix(int rows, int cols);
// void clearMemory(int **mtrx1, int m1Rows, int **mtrx2, int m2Rows);

int main()
{
    // Variable initialization:
    int m1_rows = 0, m1_cols = 0, m2_rows = 0, m2_cols = 0;

    char symmetricResponse = 'N', redoRowsAndCols = 'N';

    bool symmetricMatrix = false;

    cout << "How many rows would you like in the first matrix? ";
    cin >> m1_rows;

    cout << "How many columns would you like in the first matrix? ";
    cin >> m1_cols;

    // cout << "How many rows would you like in the second matrix? ";
    // cin >> m2_rows;

    // cout << "How many columns would you like in the second matrix? ";
    // cin >> m2_cols;

    // // Probably going to need a decision like, "Which matrix do you want to be symmetric? First, second, or neither."
    // cout << "Would you like for the matrix to be symmetric? Please enter 'Y' or 'N'.";
    // cin >> symmetricResponse;

    // // Find string function to make responses all upper case
    // symmetricResponse.uppercase();
    // // Need to test user input with a switch statement to ensure valid input.

    // // Tests if a symmetric matrix can occur
    // if (symmetricResponse == 'Y' && m1_rows != m1_cols)
    // {
    //     cout << "The matrix you entered cannot be a symmetric matrix.\n"
    //          << "The matrix will need to be a square matrix (i.e. 2x2, 3x3, etc.)\n"
    //          << "Currently your matrix is a " << m1_rows << 'x' << m1_cols << endl
    //          << "Would you like to renter your rows, columns, or choose for this to not be a "
    //             "symmetric matrix?\n";
    // }

    int seed = time(0);         
    srand(seed);

    // Initializing the first and second matrices
    int **matrix1 = new int*[m1_rows];

    for(int i = 0; i < m1_rows; i++)
        matrix1[i] = new int[m1_cols];
    
    // int **matrix2 = new int*[m2_rows];

    // for(int i = 0; i < m2_rows; i++)
    //     matrix2[i] = new int[m2_cols];

    // Calling the functions to populate the matrices
    createMatrix(matrix1, m1_rows, m1_cols);

    cout << endl;
    
    // createMatrix(matrix2, m2_rows, m2_cols);

    // Initializing an Identity Matrix (based on M1 for now, will probably change later)
    ID_Matrix(m1_rows, m1_cols);
    
    // Preventing memory leakage
    // clearMemory(matrix1, m1_rows, matrix2, m2_rows);

    return 0;
}

// Each function will correspond to a certain matrix manipulation

// Create a matrix:
void createMatrix(int **arr,int rows, int cols)
{
    // Creating the elemnts in the array/matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 10;
            cout << setw(4) << arr[i][j]; // printing out the matrix 
        }
        cout << '\n';
    }
}

// // Will create a symmetric matrix along the main diagonal.
// void symMatrix()
// {
// }

// This will create an indentity matrix of a given size. 
void ID_Matrix(int rows, int cols)
{
    int **IDmtrx = new int*[rows];

    for(int i = 0; i < rows; i++)
        IDmtrx[i] = new int[cols](); // Initalizing to 0, then change diagonal to 1

    // Creating the elements in the array/matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if(i == j)
            {
                IDmtrx[i][j] = 1;
            }
            cout << setw(4) << IDmtrx[i][j]; // printing out the matrix 
        }
        cout << '\n';
    }
}

// // Will use this function plenty. It will calculate the total dot product between two matrices
// void dotProduct(int **arr)
// {
// }

// void CR_Matrix(int **arr)
// {
// }

// void LU_Matrix(int **arr)
// {
// }

// void LDU_Matrix(int **arr)
// {
// }

// void QR_Matrix(int **arr)
// {
// }

// // Will be used to solve systems of linear equations
// void GaussElim()
// {
// }

void clearMemory(int **mtrx1, int m1Rows, int **mtrx2, int m2Rows)
{
    for (int i = 0; i < m1Rows; i++)
    {
        delete[] mtrx1[i];
    }
    delete[] mtrx1;

    for (int i = 0; i < m2Rows; i++)
    {
        delete[] mtrx2[i];
    }
    delete[] mtrx2;
}