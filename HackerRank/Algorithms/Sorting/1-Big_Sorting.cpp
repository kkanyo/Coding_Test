/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

bool cmp(string str1, string str2) {
    int len1 = str1.size();
    int len2 = str2.size();
    
    // If digits are same, compare by string
    if (len1 == len2) return str1 < str2;
    
    // If digits are different, compare by size of string
    return len1 < len2;
}

vector<string> bigSorting(vector<string> unsorted) {
    vector<string> result = unsorted;
    
    sort(result.begin(), result.end(), cmp);    // Sort by 'cmp' function
    
    return result;
}