/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    for (int i = 0; i < n; i++) {
        int j = 0;
        int middle = n-i-1;
        for (; j < middle; j++) { cout << ' '; }
        for (; j < n; j++) { cout << '#'; }
        cout << endl;
    }
}
