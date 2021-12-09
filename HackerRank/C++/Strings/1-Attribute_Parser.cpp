#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int MAX_CHAR = 200;
    
    int num_of_lines, num_of_queries;
    vector<vector<string>> hrml = {};
    vector<string> tmp;
    
    //for input
    string strinput;
    string strtmp = "";
    
    scanf("%d %d\n", &num_of_lines, &num_of_queries);
    
    //hrml.assign(num_of_lines, tmp);
    
    //input and parse HRML 
    for (int i = 0; i < num_of_lines; i++) {
        //공백무시하고 scanf로 통일해보자
        getline(cin, strinput);
        
        //parsing
        //역순으로 먼저 /tag-name 입력받고
        //입력받은 tag를 기준으로 속성과 분리해서 속성만 따로 받아야 됨
        for (int j = 1; j < MAX_CHAR; j++) {
            if (strinput[j] == ' ' || strinput[j] == '"') {
                tmp.push_back(strtmp);
                
                strtmp = "";
            }
            else if (strinput[j] == '=') {
                j += 2;
            }
            else if (strinput[j] == '>') {
                strtmp = "";
                break;
            }
            else if (strinput[j] == '/') {
                continue;
            }
            else {
                strtmp += strinput[j];
            }
        }
        
        hrml.push_back(tmp);
    }
    
    //query input
    for (int i = 0; i < num_of_queries; i++) {
        getline(cin, strinput);
        
        int n = 0;
        int m = 1;
        
        //parse query
        for (int j = 0; j < MAX_CHAR; j++) {
            //hrml 방문 순서 수정 필요
            if (strinput[j] == '.' || strinput[j] == '~') {
                while (strtmp != hrml[n][0] && n < num_of_lines/2) {
                    n++;
                }
                
                if (n >= num_of_lines/1) { 
                    printf("Not Found!\n");
                }
                
                strtmp = "";
            }
            else if (strinput[j] == 0) {
                int size = hrml[n].size();
                
                while (strtmp != hrml[n][m] && m < size - 1) {
                    m++;
                }
                
                if (m >= size) { 
                    printf("Not Found!\n");
                }
                else {
                    cout << hrml[n][m+1] << endl;
                }
                
                strtmp = "";
                break;
            }
            else {
                strtmp += strinput[j];
            }
        }
    }
    
    return 0;
}

/*
문자열을 입력받을 때 공백을 무시하고 받고 
HRML 닫는 명령문을 활용해서 tag랑 속성 분리해보면 해결할 수 있을듯
*/