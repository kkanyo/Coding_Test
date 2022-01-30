/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int result = 0;
    int maxRow = arr[0].size();     //num of rows and columns is same
    int col = maxRow-1;
    
    for (int row = 0; row < maxRow; row++, col--) {
        result += arr[row][row];    //for primary diagonol
        result -= arr[row][col];    //for secondary diagonol
    }
    
    if (result < 0) { return result *= -1;}
    else { return result; }
}
