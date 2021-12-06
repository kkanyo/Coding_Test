#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b;
    string strlist[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    cin >> a >> b;
    
    for (int i = a; i <= b; i++) {
        if (i >= 1 && i <= 9) {
            cout << strlist[i - 1] << endl;
        }
        else if (i > 9) {
            if (i % 2 < 1) {
                cout << "even\n";
            }
            else {
                cout << "odd\n";
            }
        }
    }
    
    return 0;
}

/*
Input Format

You will be given two positive integers, a and b (a <= b), separated by a newline.

Output Format

For each integer n in the inclusive interval [a,b]:

If 1 <= n <= 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".
Note: [a,b] = { x E Z | a <= x <= b} = {a, a+1, ..., b}
*/