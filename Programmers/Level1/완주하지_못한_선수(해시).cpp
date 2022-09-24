#include "stdc++.h"

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mapParticipant;                //string: participant name
                                                    //int: the number of non-complete participant (nums)
    
    for (auto i : participant) {
        if (mapParticipant.count(i) > 0) {          //If paticipants who have same name,
            mapParticipant.find(i)->second += 1;    //increase 'nums'
        }
        mapParticipant.insert(make_pair(i, 1));
    }
    
    for (auto j : completion) {                 
        auto item = mapParticipant.find(j);         //If participant complete the marathon,
        item->second -= 1;                          //decrease 'nums'
    }
    
    for (auto k : mapParticipant) {                 //If nums == 0, that participant complete the marathon.
        if (k.second == 1) {                        //If nums >= 1, he/she did not complete it.
            answer = k.first;
        }
    }
    
    return answer;
}