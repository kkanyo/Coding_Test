
/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    int min = arr[0], max = arr[0];
    long sumArr = 0;
    
    for (auto& i : arr) {
        sumArr += i;
        if (i < min) { min = i; }
        if (i > max) { max = i; }
    }
    
    cout << (sumArr-max) << " "  << (sumArr-min) << "\n";
}
