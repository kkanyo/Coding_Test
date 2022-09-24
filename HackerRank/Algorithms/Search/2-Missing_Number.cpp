#include "stdc++.h"

/*
 * Complete the 'missingNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY brr
 */

// Using map [O(M+N+K) (K <= N <= M)]
std::vector<int> missingNumbers(std::vector<int> arr, std::vector<int> brr) {
    std::vector<int> result;
    std::map<int, int> log;
    
    for (auto &num : brr) {     // Count frequency of each element
        log[num] += 1;
    }
    
    for (auto &num : arr) {     // Count backward for each element
        log[num] -= 1;
    }
    
    for (auto &cnt : log) {
        if (cnt.second > 0) {               // If frequency of element remain, 
            result.push_back(cnt.first);    // that is missing number.
        }
    }
    
    return result;
}