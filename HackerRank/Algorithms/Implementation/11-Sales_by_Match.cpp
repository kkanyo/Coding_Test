#include "stdc++.h"

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, std::vector<int> ar) {
    int nNumPairs = 0;
    std::unordered_map<int, int> mpNumColor;
    
    for (const auto &nColor : ar)
    {
        ++mpNumColor[nColor];
    }
    
    for (auto [nColor, nNum] : mpNumColor)
    {
        nNumPairs += nNum / 2;
    }
    
    return nNumPairs;
}