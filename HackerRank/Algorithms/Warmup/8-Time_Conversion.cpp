#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string militaryTime;
    
    stringstream ss;
    string strHour = s.substr(0, 2);    //split hours from 's'
    ss.str(strHour);
    
    int hour;
    ss >> hour;     //convert string to integer
    
    if (s[8] == 'A' && hour == 12) { strHour = "00"; }                      //convert hour of AM/PM format to military format
    else if (s[8] == 'P' && hour < 12) { strHour = to_string(hour+12); }
    
    militaryTime = strHour + s.substr(2, 6);    //combine hour with minute and second
    
    return militaryTime;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
