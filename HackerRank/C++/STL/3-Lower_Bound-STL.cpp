#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    vector<int> vec;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    
    vector<int>::iterator it;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        
        it = lower_bound(vec.begin(), vec.end(), tmp);
        if (*it > tmp) cout << "No ";       //If result is greater than test value(tmp)
        else cout << "Yes ";
        cout << it-vec.begin()+1 << endl;   //index of result value
    }
    
    return 0;
}
