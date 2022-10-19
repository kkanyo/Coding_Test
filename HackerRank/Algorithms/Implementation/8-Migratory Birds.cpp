#include "stdc++.h"

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(std::vector<int> arr) {
    int nLowestType = 0;
    // unorded_map 사용 시 조금 더 빠를 수는 있으나, 
    // type의 케이스가 5 이상으로 늘어날 경우 동작하지 않을 수 있다.
    // (주어진 배열의 원소들은 정렬되어 있지 않기 때문)
    std::map<int, int> mpTypeSize = {
        { 1, 0 },
        { 2, 0 },
        { 3, 0 },
        { 4, 0 },
        { 5, 0 },
    };
    
    for (const auto& nType : arr)
    {
        ++mpTypeSize[nType];
    }
    
    int nMaxSize = 0;
    // unordered_map과 map의 방문 순서가 서로 다름에 유의
    for (const auto& [nType, nSize] : mpTypeSize) {
        if ( nMaxSize < nSize ) 
        {
            nLowestType = nType;
            nMaxSize = nSize;
        }
    }
    
    return nLowestType;
}