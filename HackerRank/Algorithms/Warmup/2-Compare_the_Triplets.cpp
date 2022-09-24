#include "stdc++.h"

/*
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

std::vector<int> compareTriplets(std::vector<int> a, std::vector<int> b) {
    // [0]: Alice's Score
    // [1]: Bob's Score
    std::vector<int> nvScore(2);
    //std::vector<int> nvScore = {0, 0};

    int i = 0;
    int nNumRating = 3;
    
    for (; i < nNumRating; i++)
    {
        if (a[i] > b[i])
            nvScore[0]++;
        else if (a[i] < b[i])
            nvScore[1]++;
        else
            continue;
    }
    
    return nvScore;
}