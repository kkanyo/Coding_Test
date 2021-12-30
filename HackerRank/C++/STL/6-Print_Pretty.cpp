#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        cout << left << hex << showbase << nouppercase;     //formatting
        cout << (long long)A << endl;                       //Look out for data type
        
        cout << right << setw(15) << setfill('_');      //formatting for position 
        cout << showpos << fixed << setprecision(2);    //formatting for var
        cout << B << endl;
        
        cout << noshowpos << uppercase;             //formatting for position
        cout << scientific << setprecision(9);      //formatting for var
        cout << C << endl;
	}
	return 0;

}