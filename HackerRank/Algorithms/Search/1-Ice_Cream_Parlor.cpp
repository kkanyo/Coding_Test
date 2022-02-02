/*
 * Complete the 'icecreamParlor' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER m
 *  2. INTEGER_ARRAY arr
 */

// Brute Force [O(N^2)]
vector<int> icecreamParlor1(int m, vector<int> arr) {
    vector<int> result;
    
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == m) {
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
        }
    }
    
    return result;
}
