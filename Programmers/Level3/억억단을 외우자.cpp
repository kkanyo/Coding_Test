#include "stdc++.h"

using namespace std;

// 약수의 개수만큼 등장한다
// 4: 1, 2, 4
// 6: 1, 2, 3, 6
// 8: 1, 2, 4, 8
// 16: 1, 2, 4, 8, 16

// 1차 결과: 시간 초과
// 2차 결과: 시간 초과 (약수의 개수 산정 문제 해결)

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    int minStart = *min_element(starts.begin(), starts.end());
    vector<int> vecCountDiv(e, 0);
    
    for ( int i = 1; i <= e; i++)
    {
        for ( int j = 1; j <= e / i; j++)
        {
            ++vecCountDiv[i * j - 1];
        }
    }
    
    // 최대 등장 수를 구하는 과정에서 너무 오래 걸림
    int prevStart = e + 1;
    int divMaxAppear = 0;
    for ( const auto& start : starts )
    {        
        // 1. 범위가 늘어나면 재탐색
        // 2. 범위가 줄어들고, 이전 최대 등장 수가 범위 밖인 경우 재탐색
        if ( prevStart > start 
            || ( !answer.empty() && prevStart < start && answer.back() < start ) )
        {
            divMaxAppear = distance( vecCountDiv.begin(), 
                                    max_element( vecCountDiv.begin() + start, vecCountDiv.end() ) );

        }
        prevStart = start;

        answer.push_back( divMaxAppear );
    }
    
    return answer;
}