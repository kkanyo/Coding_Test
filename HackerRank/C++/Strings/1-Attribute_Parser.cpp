#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num_of_lines, num_of_queries;
    vector<vector<string>> hrml_list;
    vector<string> hrml;
    vector<string> query;
    
    string input_str;
    string tmp_str = "";
    char input_ch;
    
    scanf("%d %d", &num_of_lines, &num_of_queries);
    
    //fill in HRML lsit applying parsing string
    for (int i = 0; i < num_of_lines/2; i++) {
        cin >> input_str;
        //!-------incorrect input ??????
        cout << input_str;
        for (int j = 0; j < input_str.size(); j++) {
            input_ch = input_str[j];
            
            if (input_ch == '<') {
                continue;
            }
            else if (input_ch == '=') {
                j += 1;
            }
            else if (input_ch == ' ' || input_ch == '>') {
                //push hrml parsing string and initalize tmp_str
                hrml.push_back(tmp_str);
                
                tmp_str = "";
                
                if (input_ch == '>') { break; }
            }
            else {
                if (input_ch != '"') {
                    tmp_str += input_ch;
                }
            }
        }
        hrml_list.push_back(hrml);
    }
    
    //print value of the attribute for each query
    for (int i = 0; i < num_of_queries; i++) { 
        cin >> input_str;
        
        //parse query
        //tag1 tag2 name ~ .
        for (int j = 0; j < input_str.size(); j++) {
            input_ch = input_str[j];
            
            if (input_ch == '.' || input_ch == '~') {
                query.push_back(tmp_str);
                tmp_str = "";
                
                if (input_ch == '.') { query.push_back("."); }
                else { query.push_back("~"); }
            }
            else{
                tmp_str += input_ch;
            }
        }
        
        //!-------Compile Error!!!! :(
        //<<print value>>
        vector<string>::iterator iter_q = query.begin();
        int k;
        
        //cout << hrml_list[0][0];
        /*
        //compare tag 
        for (k = 0; k < num_of_lines/2; k++) {
            if ( *iter_q == *(hrml_list[0].begin()) ) {
                iter_q++;
                
                if (*iter_q == ".") { iter_q++; }
                else { break; }
            }
            else {
                printf("Not Found!");
                break;
            }
        }
        /*
        vector<string>::iterator iter_h = hrml_list[k].begin();
        
        for (; iter_h != hrml_list[k].end() - 1; iter_h += 2) {
            if (*iter_q == *iter_h) {
                cout << *(iter_h + 1);
                break;
            }
        }
        */
    }
    
    return 0;
}
