#include "stdc++.h"

/*
 * Complete the 'insertionSort2' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */
 
// Print elements of vector
void printArr(std::vector<int> arr) {
    for (auto &num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void insertionSort2(int n, std::vector<int> arr) {
    for (int i = 1; i < n; i++) {
        int tmp = arr[i];
        int j = i-1;    // prev
        
        while (arr[j] > tmp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
        printArr(arr);
    }
}