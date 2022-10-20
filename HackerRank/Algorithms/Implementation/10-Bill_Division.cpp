#include "stdc++.h"

/*
 * Complete the 'bonAppetit' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY bill
 *  2. INTEGER k
 *  3. INTEGER b
 */

void bonAppetit(std::vector<int> bill, int k, int b) {
    int nCostShared = 0;
    int nSizeBill = bill.size();
    
    // calculate total cost of the shared items
    for (int i = 0; i < nSizeBill; i++)
    {
        // pass the item that Anna did not eat
        if (i == k) continue;
        
        nCostShared += bill[i];
    }
    nCostShared /= 2;
    
    // compare how many charged Anna
    if (nCostShared == b)
        printf("Bon Appetit");
    else
        printf("%d", nCostShared < b ? b - nCostShared : nCostShared - b);
        
    return;
}