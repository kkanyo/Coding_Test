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
    
    string special_ch = "!@#$%^&*()-+";
    bool check[4] = {false,}; // 0:number, 1:lower case, 2:upper case, 3:special character
    
    for (auto& ch : password) {
        if (ch >= '0' && ch <= '9') {           // check to contain number
            check[0] = true; 
        } else if (ch >= 'a' && ch <= 'z') {    // check to contain lower case
            check[1] = true; 
        } else if (ch >= 'A' && ch <= 'Z') {    // check to contain upper case
            check[2] = true; 
        } else {
            for (auto& sp_ch : special_ch) {    // check to contain special character
                if (ch == sp_ch) { check[3] = true; }
            }
        }
    }
    
    // If password do not contain character for strong password
    for (auto& it : check) {    
        if (!it) result++;
    }
    
    // If password with character requiring is shorter than 6
    if (n + result < 6) {       
        result += 6-(n+result);
    }
    
    return result;
}