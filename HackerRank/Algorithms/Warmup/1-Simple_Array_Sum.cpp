#include "stdc++.h"

/*
 * Complete the 'simpleArraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as parameter.
 */

int simpleArraySum(std::vector<int> ar) {
    int result = 0;
    
    for (auto& i : ar) {     //roof vector ar
        result += i++;
    }
    
    return result;
}