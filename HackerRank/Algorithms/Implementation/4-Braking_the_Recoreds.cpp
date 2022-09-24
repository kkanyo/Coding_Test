#include "stdc++.h"

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

int* breakingRecords(std::vector<int> scores) {
    int nvTimesBreakRec[2] = {0};
    
    int nMaxScore = scores[0];
    int nMinScore = nMaxScore;
    
    for (const auto& elem : scores)
    {
        if (elem > nMaxScore)
        {
            nMaxScore = elem; 
            nvTimesBreakRec[0]++;
        }
        else if (elem < nMinScore)
        {
            nMinScore = elem;
            nvTimesBreakRec[1]++;
        }
    }
    
    return nvTimesBreakRec;
}