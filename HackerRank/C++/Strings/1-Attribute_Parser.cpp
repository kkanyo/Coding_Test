#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
This time Let's use tree structure...
It's sooooo hard problem for me :(
but do not give up
*/
struct hrml {
    string tag;
    vector<string> attributes;
    vector<string> values;
};

struct tree_node {
    struct hrml node;
    vector<struct tree_node*> children;
    struct tree_node* parent;
};

int main() {
    int num_of_lines, num_of_queries;
    struct tree_node* root = new struct tree_node;
    struct tree_node* now_level = root;
    
    string strinput;
    
    scanf("%d %d\n", &num_of_lines, &num_of_queries);

    //input and parse HRML 
    for (int i = 0; i < num_of_lines; i++) {
        string strtmp = "";
        
        getline(cin, strinput);
        cin.ignore();
        
        int strinput_size = strinput.size();
        
        //parsing
        for (int j = 1; j < strinput_size; j++) {
            //for end tag
            if (strinput[j] == '/')
            {
                j += 1;
                while (j < strinput_size - 1) {
                    strtmp += strinput[j];
                }
                now_level->node.tag = strtmp;
                now_level = now_level->parent;
            }
            else {
                struct tree_node* new_node = new struct tree_node;
                
                if (strinput[j] == ' ') {
                    new_node->node.attributes.push_back(strtmp);
                    strtmp = "";
                }
                else if (strinput[j] == '=') {
                    j += 2;
                }
                else if (strinput[j] == '\"') {
                    new_node->node.attributes.push_back(strtmp);
                    strtmp = "";
                }
                else if (strinput[j] == '>') {
                    break;
                }
                else {
                    strtmp += strinput[j];
                }
                
                now_level->children.push_back(new_node);
                now_level = new_node;
            }
        }
    }
    
    /*
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
    */
    return 0;
}
