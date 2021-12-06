#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    int intList[1000] = { 0 };
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &intList[i]);
    }
    
    for (int i = N - 1; i >= 0; i--) {
        printf("%d ", intList[i]);
    }
    
    return 0;
}

/*
You will be given an array of N integers and you have to print the integers in the reverse order.

Input Format

The first line of the input contains N,where N is the number of integers.The next line contains N space-separated integers.

Constraints

1 <= N <= 1000
1 <= A[i] <= 10000, where A[i] is the 'i'th integer in the array.

Output Format

Print the N integers of the array in the reverse order, space-separated on a single line.
*/