#include "stdc++.h"

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    int row = 0;
    
    for (; row < n; row++)
    {
        int col = 0;
        int mid = n - row - 1;
        
        for (; col < n; col++)
        {
            if ( col < mid )
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
