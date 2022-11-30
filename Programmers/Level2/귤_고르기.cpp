#include "stdc++.h"

using namespace std;

// 1. unordered_map을 활용한 풀이
bool ComparePairValueGreater(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

int solution1(int k, vector<int> tangerine) {
    int answer = 0;
    int countBoxTangerine = 0;
    unordered_map<int, int> mapSizeCount;
    
    // 각 크기별 개수를 계산
    for ( const auto &size : tangerine )
    {
        ++mapSizeCount[size];
    }
    
    // 개수를 기준으로 정렬
    vector<std::pair<int, int>> listSizeCount(mapSizeCount.begin(), mapSizeCount.end());
    sort(listSizeCount.begin(), listSizeCount.end(), ComparePairValueGreater);
    
    // 개수가 가장 많은 크기부터 상자에 담는다
    for ( const auto &sizeCount : listSizeCount )
    {
        countBoxTangerine += sizeCount.second;
        ++answer;
        
        if (countBoxTangerine >= k) { break; }
    }
        
    return answer;
}
