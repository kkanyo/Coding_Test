#include "stdc++.h"

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, std::string path) {
    int nCountValleys = 0;
    int nHeight = 0;
    
    for (const auto& step : path)
    {        
        if (step == 'U')
        {
            ++nHeight;
            // In problem, a moutain is 
            // a sequence of consecutive steps above sea level,
            // ending with a step down to sea level.
            // We need to consider that height is '0' after stepping up.
            if ( nHeight == 0 ) ++nCountValleys;           
        }
        else
            --nHeight;
    }
    
    return nCountValleys;
}