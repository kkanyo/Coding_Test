/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int numApples = 0, numOranges = 0;
    
    // Check position of apples
    for (auto& it : apples) {
        // Calculate position of fruit
        int posApple = it+a;
        // If the fruit located in house
        if (posApple >= s && posApple <= t) { numApples++; }    // Increase # of fruits
    }
    
    // Check position of oranges
    for (auto& it : oranges) {
        int posOrange = it+b;
        if (posOrange >= s && posOrange <=t) { numOranges++; }
    }
    
    cout << numApples << "\n" << numOranges;
}