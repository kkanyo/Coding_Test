#include <string>
#include <vector>
#include <map>

using namespace std;

// 1차 시도: 일부 테스트 케이스 실패

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    map<int, int> mpProgressRound;
    
    for (const auto &numEnemy : enemy)   
    {
        n -= numEnemy;
        ++mpProgressRound[numEnemy];
        
        while ( n < 1 ) {
            if ( k < 1)
                return answer;
            else {
                // 무적권이 남은 상태로 라운드 진행이 불가하면
                // 진행한 라운드 중 적의 수가 가장 많은 라운드에
                // 무적권을 사용한 것으로 간주하고, 병사 수 회복
                int recovery = mpProgressRound.rbegin()->first;
                
                n += recovery;
                if ( --mpProgressRound[recovery] < 1) {
                    mpProgressRound.erase(recovery);
                }
                
                --k;
            }
        }
        
        ++answer;
    }
    
    return answer;
}