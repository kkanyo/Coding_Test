#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, ab;
    char tmp;   //for saving first characters of a (because of 'pointer')
    
    cin >> a >> b;
    cin.ignore();
    
    cout << a.size() << " " << b.size() << endl;
    cout << (a + b) << endl;
    
    tmp = a.at(0);
    a.at(0) = b.at(0);
    b.at(0) = tmp;
    
    cout << a << " " << b;
    
    return 0;
}
