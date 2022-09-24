#include "stdc++.h"

/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

long aVeryBigSum(std::vector<long> ar) {
    long result = 0;
    
    for (auto& i : ar) {
        result += i++;
    }
    
    return result;
}