/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int result = 0;
    bool check[4] = {false,}; // 0:number, 1:lower case, 2:upper case, 3:special character
    
    for (auto& ch : password) {
        if (ch >= '0' && ch <= '9') {           // check containing number
            check[0] = true; 
        } else if (ch >= 'a' && ch <= 'z') {    // check containing lower case
            check[1] = true; 
        } else if (ch >= 'A' && ch <= 'Z') {    // check containing upper case
            check[2] = true; 
        } else if (ch=='!' || ch=='@' || ch=='#' || ch=='$' || ch =='%'
            || ch=='^' || ch=='&' || ch=='*' || ch=='(' || ch ==')'
            || ch=='-' || ch=='+') {            // check containing special character
                check[3] = true;
            }
    }
    
    for (auto& it : check) {    // If password do not contain character for strong password
        if (!it) result++;
    }
    
    if (n + result < 6) {       // If password with character requiring is shorter than 6
        result += 6-(n+result);
    }
    
    return result;
}