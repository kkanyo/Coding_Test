/*
 * Complete the 'compareTriplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int scoreAlice = 0, scoreBob = 0;
    vector<int> scores;
    
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) { scoreAlice++; }      //Alice is awarded
        else if (a[i] < b[i]) { scoreBob++; }   //Bob is awarded
    }
    
    scores.push_back(scoreAlice);       //push scores in vector
    scores.push_back(scoreBob);
    
    return scores;
}