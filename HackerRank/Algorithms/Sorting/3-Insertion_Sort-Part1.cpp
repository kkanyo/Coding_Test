/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

// Print elements of Array
void printArr(vector<int> arr) {
    for (auto& num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

void insertionSort1(int n, vector<int> arr) {
    int tmp = arr[n-1];
    
    int i = n-2;
    while (arr[i] > tmp) {
        arr[i+1] = arr[i];
        printArr(arr);
        i--;
    }
    arr[i+1] = tmp;
    printArr(arr);
}