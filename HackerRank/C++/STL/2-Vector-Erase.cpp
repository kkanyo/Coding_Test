#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, del_pos, del_begin, del_end;
    vector<int> vec;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        
        vec.push_back(tmp);
    }
    
    cin >> del_pos;
    vec.erase(vec.begin() + del_pos - 1);   //delete element at del_pos
    
    cin >> del_begin >> del_end;
    vec.erase(vec.begin()+del_begin-1, vec.begin()+del_end-1);  //delete range of del_pos to del_end-1
    
    cout << vec.size() << endl;
    for (auto v: vec) {
        cout << v++ << " ";
    }
    
    return 0;
}
