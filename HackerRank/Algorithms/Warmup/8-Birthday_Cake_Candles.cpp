/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(vector<int> candles) {
    int result = 0;
    int maxHeight = candles[0];     //temporary max value
    
    for (auto& i : candles) {
        if (i > maxHeight) {        //If element is bigger than 'maxHeight',
            maxHeight = i;          //update 'maxHeight' to bigger value and initailize result
            result = 1;
        }
        else if (i == maxHeight) {
            result++;
        }
    }
    
    return result;
}
