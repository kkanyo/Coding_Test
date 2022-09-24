#include "stdc++.h"

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(std::vector<int> arr) {
    float plus = 0, minus = 0, zero = 0;
    int size = arr.size();
    
    for (auto& i : arr) {
        if (i > 0) { plus++; }
        else if (i < 0) { minus++; }
        else { zero++; }
    }
    
    std::cout << plus/size << "\n";      //If all of operand are integer,
    std::cout << minus/size << "\n";     //you will convert data type to float or double
    std::cout << zero/size << "\n";
}
