#include "stdc++.h"

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */


// 1. Using double loop
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


// ----------------
// Using LCM, GCD
int GetGCD(int nNum1, int nNum2)
{
    if (nNum1 < 0 || nNum2 < 0)
        return 0;
    
    if (nNum1 == nNum2)
        return nNum1;
    
    int nLeft = nNum1 > nNum2 ? nNum1 : nNum2;
    int nRight = nNum1 < nNum2 ? nNum1 : nNum2;
    int nRemain = 1;
    
    while (nRemain > 0)
    {
        nRemain = nLeft % nRight;
        nLeft = nRight;
        nRight = nRemain;
    }
    
    return nLeft;
}

int GetLCM(int nNum1, int nNum2)
{
    if (nNum1 < 0 || nNum2 < 0)
        return 0;

    if (nNum1 == nNum2)
        return nNum1;
    
    return nNum1 * nNum2 / GetGCD(nNum1, nNum2);
}

int getTotalX(std::vector<int> a, std::vector<int> b) {
    int result = 0;
    
    int nLCM = a[0];
    int nGCD = b[0];    
    
    // 첫번째 배열의 원소들에 대한 최소공배수
    for (int i = 1; i < a.size(); i++)
        nLCM = GetLCM(nLCM, a[i]);
    
    // 두번째 배열의 원소들에 대한 최대공약수
    for (int i = 1; i < b.size(); i++)
        nGCD = GetGCD(nGCD, b[i]);
    
    
    // GCD의 약수 중 LCM의 배수인 수는 문제의 조건을 만족
    for (int i = nLCM; i <= nGCD; i += nLCM)
        if (nGCD % i == 0)
            result++;
    
    return result;
}