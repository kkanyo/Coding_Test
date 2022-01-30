/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    string result;
    
    int i=0;
    while (i < s.size()-1 && !s.empty()) {
        if (s[i] == s[i+1]) {
            s.erase(i, 2);          // Length of string is changed
            if (i > 0) { i--; }     // Re-check previous character of string
        }
        else i++;
    }

    if (s.empty()) result = "Empty String";
    else result = s;
    
    return result;
}