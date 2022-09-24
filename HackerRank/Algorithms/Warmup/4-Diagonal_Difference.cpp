#include "stdc++.h"

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(std::vector<std::vector<int>> arr) {
    int nDiagonalDiff = 0;
    int i = 0;
    int nNumCols = arr.size();
    
    // arr is square matrix
    for (; i < nNumCols; i++)
    {
        nDiagonalDiff += arr[i][i];
        nDiagonalDiff -= arr[i][nNumCols - i - 1];
    }
    
    return nDiagonalDiff > 0 ? nDiagonalDiff : -nDiagonalDiff;
}
