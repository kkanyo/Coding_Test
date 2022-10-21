/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
    // 1. start to front
    int nMinTurn = p / 2;
    
    // 2. start to back
    if ( n % 2 == 0 && (n - p + 1) / 2 < nMinTurn)
        nMinTurn = (n - p + 1) / 2;
    else if ( (n - p) / 2 < nMinTurn )
        nMinTurn = (n - p) / 2;
    
    return nMinTurn;
}

int pageCount2(int n, int p) {
    // 1. start to front
    int nMinTurn = p / 2;
    
    // 2. start to back
    // n, n+1 (n is even number) -> x pair pages
    if ( n / 2 - p / 2 < nMinTurn)
        nMinTurn = n / 2 - p / 2;
    
    return nMinTurn;
}