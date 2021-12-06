#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    
    string strlist[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (n >= 1 && n <= 9) {
        cout << strlist[n-1];
    }
    else if (n > 9) {
        cout << "Greater than 9";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

/*
Given a positive integer , do the following:

If 1 <= n <= 9, print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.).
If n > 9, print Greater than 9.
Input Format

A single integer, 'n'.

Constraints
1 <= n <= 10^9

Output Format

If 1 <= n <= 9, then print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.); otherwise, print Greater than 9.
*/