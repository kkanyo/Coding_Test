#include <vector>
#include <algorithm>

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(std::vector<int> a, std::vector<int> b) {
    int result = 0;
    
    // 두번째 배열의 가장 작은 값을 구하기 위해 정렬
    std::sort(b.begin(), b.end());
    
    for (int i = b[0]; i > 0; i--)
    {
        int nCheckFirst = 0;
        int nCheckSecond = 0;
        
        // 첫번째 배열의 원소들에 대해 공배수인지 확인
        for (const auto &elem : a)
        {
            if (i % elem == 0)
                nCheckFirst++;
        }

        // 두번째 배열의 원소들에 대해 공약수인지 확인
        for (const auto &elem : b)
        {
            if (elem % i == 0)
                nCheckSecond++;
        }
        
        // 위 두 조건을 모두 만족한 경우 증가
        if (nCheckFirst >= a.size() && nCheckSecond >= b.size())
            result++;
    }
    
    return result;
}