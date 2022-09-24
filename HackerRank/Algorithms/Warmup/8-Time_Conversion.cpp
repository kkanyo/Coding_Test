#include "stdc++.h"
#include <sstream>

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

std::string timeConversion(std::string s) {
    std::string militaryTime;
    
    std::stringstream ss;
    std::string strHour = s.substr(0, 2);    //split hours from 's'
    ss.str(strHour);
    
    int hour;
    ss >> hour;     //convert string to integer
    
    if (s[8] == 'A' && hour == 12) { strHour = "00"; }                      //convert hour of AM/PM format to military format
    else if (s[8] == 'P' && hour < 12) { strHour = std::to_string(hour+12); }
    
    militaryTime = strHour + s.substr(2, 6);    //combine hour with minute and second
    
    return militaryTime;
}
