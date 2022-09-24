#include "stdc++.h"

/*
 * Complete the 'balancedSums' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

std::string balancedSums(std::vector<int> arr) {
    int size = arr.size();
    // If size of array is 1, answer is always "YES"
    if (size == 1) return "YES";
    
    int left_sum = 0;   // Sum of element of left subarray
    int right_sum = 0;  // Sum of element of right subarray
    
    for (auto &num : arr) {
        right_sum += num;
    }
    
    // Update 'left_sum' and 'right_sum' based on current element
    for (auto &num : arr) {
        right_sum -= num;
        if (left_sum == right_sum) { return "YES"; }
        left_sum += num;
    }
    
    return "NO";
}
