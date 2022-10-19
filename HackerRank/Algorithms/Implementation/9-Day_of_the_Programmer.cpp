#include "stdc++.h"

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

std::string dayOfProgrammer(int year) {
    int nDay = 13;
    
    // Gregorian calendar
    if ( year > 1918 &&
     ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) )
            --nDay;
    // Julian calendar
    else if ( year < 1918 && year % 4 == 0 )
            --nDay;
    // in 1918
    else if ( year == 1918 )
        nDay += 13;
    
    return std::to_string(nDay) + ".09." + std::to_string(year);
}