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

// Using map stl [O(N)]
// We need to search "pair" to make sum result to 'm'
vector<int> icecreamParlor(int m, vector<int> arr) {
    vector<int> result;
    map<int, int> log;
    
    for (int i = 0; i < arr.size(); i++) {
        int first = arr[i];
        int second = m - first;     // m = first + second
        
        int j = log[second];        // Get index of value 'second'
        
        if (j != 0) {               // If know index of value 'second'
            result.push_back(j);
            result.push_back(i+1);
            break;
        }
                                    // If don't know index of value 'second',
        log[first] = i+1;           // store index of value 'first'
    }
    
    return result;
}