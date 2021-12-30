#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int maxQuery;
    cin >> maxQuery;
    
    int order, num;
    set<int> setInt;
    
    for(int i = 0; i < maxQuery; i++) {
        cin >> order >> num;
        
        switch (order) {
            case 1:     //Add an element to set
                setInt.insert(num);
                break;
            case 2:     //Delete an element from set
                setInt.erase(num);
                break;
            case 3:     //Check for value
                if (setInt.find(num) != setInt.end()) cout << "Yes\n";
                else cout << "No\n";
                break;
        }
    }
    
    return 0;
}