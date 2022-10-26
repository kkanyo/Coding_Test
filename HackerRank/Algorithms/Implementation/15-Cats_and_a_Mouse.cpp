#include "stdc++.h"

unsigned int GetAbsoluteVal(int nNum)
{
    if ( nNum < 0 )
        return nNum * -1;
    else
        return nNum;
}

// Complete the catAndMouse function below.
std::string catAndMouse(int x, int y, int z) {
    std::string sWinner = "";
    unsigned int nDiffAtoC = GetAbsoluteVal(x - z);
    unsigned int nDiffBtoC = GetAbsoluteVal(y - z);
    
    if ( nDiffAtoC < nDiffBtoC )
        sWinner = "Cat A";
    else if ( nDiffAtoC > nDiffBtoC )
        sWinner = "Cat B";
    else
        sWinner = "Mouse C";
        
    return sWinner;
}