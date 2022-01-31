/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

bool cmp(string str1, string str2) {
    return (int)str1.size() < (int)str2.size();
}

vector<string> bigSorting(vector<string> unsorted) {
    vector<string> result = unsorted;
    
    sort(result.begin(), result.end());         // Sort by string
    sort(result.begin(), result.end(), cmp);    // Sort by size of string
    
    return result;
}
