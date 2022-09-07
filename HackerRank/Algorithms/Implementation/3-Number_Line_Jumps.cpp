#include <string>

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

// Use loop
std::string kangaroo(int x1, int v1, int x2, int v2) {
    // If jump degree of first kangaroo is shorter than second one
    // it cannot follow sceond one
    int _x1 = x1;   int _x2 = x2;
    int _v1 = v1;   int _v2 = v2;

    if (_v1 <= _v2) return "NO";
    
    while (_x1 < _x2) {
        _x1 += _v1;
        _x2 += _v2;
    }
    
    if (_x1 == _x2) { return "YES"; }
    else return "NO";
}

// O(1)
// Not use loop
// Those kangaroos only jump once at the same time.
// So, the location diff is narrowed in proportion to diff of jump distance.        
std::string kangaroo(int x1, int v1, int x2, int v2) {
    int nDiffLocation = x2 - x1;
    int nDiffJumpDist = v1 - v2;
    
    if (nDiffJumpDist < 0) return "NO";
    
    // Remainder is not 0 means that kangaroo1 jump over kangaroo2
    return (nDiffLocation % nDiffJumpDist == 0) ? "YES" : "NO"; 
}