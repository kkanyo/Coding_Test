/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

string kangaroo(int x1, int v1, int x2, int v2) {
    // If jump degree of first kangaroo is shorter than second one
    // it cannot follow sceond one
    if (v1 <= v2) return "NO";
    
    while (x1 < x2) {
        x1 += v1;
        x2 += v2;
    }
    
    if (x1 == x2) { return "YES"; }
    else return "NO";
}