#include "stdc++.h"

/*
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */

int divisibleSumPairs(int n, int k, std::vector<int> ar) {
    int nCountPairs = 0;
    
    for (int i = 0; i < n - 1; i++)
    {        
        //(i, j) pairs where i < j
        for (int j = i + 1; j < n; j++)
        { 
            if ( ( ar[i] + ar[j] ) % k == 0 ) nCountPairs++;
        }
    }
    
    return nCountPairs;
}