#include "stdc++.h"

/*
 * Complete the 'birthday' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY s
 *  2. INTEGER d
 *  3. INTEGER m
 */

int birthday(std::vector<int> s, int d, int m) {
    int nChocoSize = s.size();
    int nNumDivChoco = 0;
    
    for (int i = 0; i < nChocoSize - m + 1; i++)
    {
        int nSum = s[i];
        
        for (int j = i + 1; j < i + m; j++)
        {
             nSum += s[j];
             if ( nSum > d ) break;
        }
        
        if ( nSum == d ) ++nNumDivChoco;
    }
    
    return nNumDivChoco;
}