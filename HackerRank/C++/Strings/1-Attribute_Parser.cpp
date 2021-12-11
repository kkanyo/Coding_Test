#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num_of_lines, num_of_queries;
    
    //for input
    string strinput;
    vector<string> vectmp;

    scanf("%d %d\n", &num_of_lines, &num_of_queries);
    
    vector<vector<string>> hrml(num_of_lines/2);
    vector<string> tag;
    
    int hrml_index = 0;

    //input and parse HRML 
    for (int i = 0; i < num_of_lines; i++) {
        string strtmp = "";
        
        getline(cin, strinput);
        
        int strinput_size = strinput.size();
        
        //parsing
        for (int j = 1; j < strinput_size; j++) {
            //for </tag>
            if (strinput[j] == '/')
            {
                j += 1;
                while (j < strinput_size - 1) {
                    strtmp += strinput[j++];
                }
                tag.push_back(strtmp);
                break;
            }
            else if (strinput[j] == ' ' || strinput[j] == '"') {
                hrml[hrml_index].push_back(strtmp);
                strtmp = "";
            }
            else if (strinput[j] == '=') {
                j += 2;
            }
            else {
                strtmp += strinput[j];
            }
        }
        hrml_index += 1;
    }
    /*
    for (int i = 0; i < num_of_lines/2; i++) {
        cout << tag[i] << endl;
    }
    
    for (int i = 0; i < num_of_lines/2; i++) {
        for (int j = 0; j < hrml[i].size(); j++) {
            cout << hrml[i][j] << endl;
        }
    }
    */
    
    //query input
    for (int i = 0; i < num_of_queries; i++) {
        string strtmp = "";
        vector<string> query;
        
        getline(cin, strinput);
        
        int strinput_size = strinput.size();
        
        //parse query
        for (int j = 0; j < strinput_size; j++) {
            if (strinput[j] == '.') {
                query.push_back(strtmp);
                strtmp = "";
            }
            else if (strinput[j] == '~') {
                query.push_back(strtmp);
                strtmp = "";
                
                while (j < strinput_size - 1) {
                    strtmp += strinput[++j];
                }
                
                query.push_back(strtmp);
            }
            else {
                strtmp += strinput[j];
            }
        }
        
        int t = tag.size() - 1;
        
        //compare tag
        for (int j = 0; j < query.size() - 2; j++) {
            for (; t > 0; t--) {
                if (query[j] != tag[t]) {
                    printf("Not Found!\n");
                    break;
                }
            }
        }
        
        int select_hrml;

        //matching tag to hrml
        for (int j = 0; j < num_of_lines/2; j++) {
            if (hrml[j][0] == tag[t]) {
                for (int k = 1; k < hrml[j].size() - 1; k += 1) {
                    if (hrml[j][k].compare(query[query.size() - 1]) == 0) {
                        cout << hrml[j][k + 1] << endl;
                        break;
                    }
                    else {
                        printf("Not Found!\n");
                    }
                }
            }
        }
    }
    
    return 0;
}

/*
Incorrect....

Next time I'll try using a struct or class.
*/