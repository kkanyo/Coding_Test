#include "stdc++.h"

/*
 * Complete the getMoneySpent function below.
 */

bool IsGreaterThan(int nLeft, int nRight) { return nLeft > nRight; }

int getMoneySpent(std::vector<int> keyboards, std::vector<int> drives, int b) {
    int nMaxSpent = -1;
    int nSizeKeyboards = keyboards.size();
    int nSizeDrives = drives.size();
    
    sort(keyboards.begin(), keyboards.end(), IsGreaterThan);
    sort(drives.begin(), drives.end());
    
    // When comparing relatively inexpensive keyboards,
    // there is no need to consider the low-cost drives
    // compared to expensive keyboards.
    for ( int i = 0, j = 0; i < nSizeKeyboards; i++)
    {
        for ( ; j < nSizeDrives; j++)
        {
            if ( keyboards[i] + drives[j] > b )
                break;
            else if ( keyboards[i] + drives[j] > nMaxSpent)
                nMaxSpent = keyboards[i] + drives[j];
        }
    }
    
    return nMaxSpent;
}