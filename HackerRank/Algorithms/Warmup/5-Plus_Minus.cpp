/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    float plus = 0, minus = 0, zero = 0;
    int size = arr.size();
    
    for (auto& i : arr) {
        if (i > 0) { plus++; }
        else if (i < 0) { minus++; }
        else { zero++; }
    }
    
    cout << plus/size << endl;      //If all of operand are integer,
    cout << minus/size << endl;     //you will convert data type to float or double
    cout << zero/size << endl;
}
