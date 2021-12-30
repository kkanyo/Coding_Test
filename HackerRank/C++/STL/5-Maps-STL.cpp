#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int maxQuery;
    cin >> maxQuery;
    
    map<string, int> studentsMap;
    int order, mark;
    string name;
    
    for (int i = 0; i < maxQuery; i++) {
        cin >> order >> name;
        
        switch (order) {
            case 1:     //Add the marks to the student
                cin >> mark;
                if (studentsMap.count(name) > 0) {  //already entered student
                    studentsMap[name] += mark;
                }
                else {
                    studentsMap.insert(make_pair(name, mark));
                }
                break;
            case 2:     //Erase the marks of the student
                studentsMap.erase(name);
                break;
            case 3:     //Pinrt the marks of the student
                if (studentsMap.count(name) > 0) cout << studentsMap[name] << endl;
                else cout << 0 << endl;
                break;
        }
    }
    return 0;
}



