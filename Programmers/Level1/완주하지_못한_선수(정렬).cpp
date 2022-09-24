#include "stdc++.h"

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    auto j = participant.begin();
    for (auto i : completion) {     //compare two vectors
        if (i != *j) {              //sorting order is not same means
            answer = *j;            //that participant do not complete the marathon
            return answer;
        }
        j++;
    }
    
    answer = *j;                    //Participant of last is do not complete the marathon
    
    return answer;
}