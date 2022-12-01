#include "stdc++.h"

using namespace std;

// 1을 제외한 모든 수는 최소 2번 등장
// 1을 제외한 소수는 2번만 등장
// 약수의 개수만큼 등장한다
// 4: 1, 2, 4
// 6: 1, 2, 3, 6
// 8: 1, 2, 4, 8
// 16: 1, 2, 4, 8, 16

// 1차 결과: 시간 초과

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    int minStart = *min_element(starts.begin(), starts.end());
    vector<int> vecAppearCount(e, 0);
    
    // 약수를 구하는 계산이 너무 느림
    for ( int i = minStart; i <= e; i++ )
    {        
        for (int j = 1; j * j <= i; j++) 
        {
            if (i % j == 0) {
                vecAppearCount[i - 1]++;
                if (j * j < i) {
                    vecAppearCount[i - 1]++;
                }
            }
        }
    }
    
    for ( const auto& num : starts )
    {
        if ( num == e ) { answer.push_back(num); }
        else
        {
            // vecAppearCount의 크기가 커지면 탐색 시간이 오래 걸림
            answer.push_back( distance( vecAppearCount.begin(), 
                                   max_element( vecAppearCount.begin() + num - 1, vecAppearCount.end() ) ) + 1 );
        }
        
    }
    
    return answer;
}