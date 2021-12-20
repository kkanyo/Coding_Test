#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    char ch;
    int tmp_num;
    vector<int> result;
    
    while (ss >> tmp_num) {
        result.push_back(tmp_num);
        ss >> ch;
    }
    
    return result;
}

int main() {
    string str;
    
    cin >> str;
    
    vector<int> integers = parseInts(str);
    
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}