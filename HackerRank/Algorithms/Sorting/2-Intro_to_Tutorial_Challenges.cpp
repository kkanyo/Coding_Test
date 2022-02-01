/*
 * Complete the 'introTutorial' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER V
 *  2. INTEGER_ARRAY arr
 */

int introTutorial(int V, vector<int> arr) {
    int result = -1;
    
    sort(arr.begin(), arr.end());
    
    for (auto& num : arr) {
        result++;
        if (num == V) break;
    }
    
    return result;
}
