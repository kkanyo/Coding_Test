#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q, k, num, i, j;
    vector<vector <int>> vec;
    vector<int> vecTmp;         //For assigning vec
    
    scanf("%d %d", &n, &q);
    vec.assign(n, vecTmp);

    for (int a = 0; a < n; a++) {
        scanf("%d", &k);
        
        //fill in vec
        for (int b = 0; b < k; b++) {
            scanf("%d", &num);
            vec.at(a).push_back(num);
        }
    }
    
    for (int a = 0; a < q; a++) {
        scanf("%d %d", &i, &j);
        
        printf("%d\n", vec.at(i).at(j));
    }
    
    return 0;
}

/*
The first line contains two space-separated integers denoting the respective values of n (the number of variable-length arrays) and q (the number of queries).
Each line i of the n subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 … a[i]k-1 describing the k-element array located at a[i].
Each of the q subsequent lines contains two space-separated integers describing the respective values of i (an index in array a) and j (an index in the array referenced by a[i]) for a query.

Constraints
1 <= n <= 10^5
1 <= q <= 10^5
1 <= k <= 3*10^5
n <= sum(k) <= 3*10^5
0 <= i < n
0 <= j < k

All indices in this challenge are zero-based.
All the given numbers are non negative and are not greater than 10^6
Output Format

For each pair of i and j values (i.e., for each query), print a single integer that denotes the element located at index i of the array referenced by a[i]. There should be a total of q lines of output.
*/