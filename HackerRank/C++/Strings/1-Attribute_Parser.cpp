#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
String values are incorrectly input to node...
I think this problem is about to 'pointer'
If it doesn't work even after trying agiain, refer to answer
*/

struct tree_node {
    string tag;
    vector<string> attributes;
    vector<string> values;
    vector<struct tree_node*> children;
    struct tree_node* parent;
};

void HrmlParse(string hrml, struct tree_node* current_level) {
    int i = 1;
    
    //for closing tag
    if (hrml[i] == '/') {
        current_level = current_level->parent;
    }
    else {
        struct tree_node* new_node = new struct tree_node;
        //input tag
        while (hrml[i] != ' ' && hrml[i] != '>') i++;
        new_node->tag = hrml.substr(1, i-1);
        
        int mark;
        
        while (hrml[i] != '>') {
            mark = ++i;
            
            //input attributes
            while (hrml[i] != ' ') i++;
            new_node->attributes.push_back(hrml.substr(mark, i-mark));
            
            //input value
            while (hrml[i] != '\"') i++;
            mark = ++i;
            while (hrml[i] != '\"') i++;
            new_node->values.push_back(hrml.substr(mark, i-mark));
            ++i;
        }
        
        current_level->children.push_back(new_node);
        new_node->parent = current_level;
        current_level = new_node;
    }
}

int main() {
    int num_of_lines, num_of_queries;
    struct tree_node* root = new struct tree_node;
    struct tree_node* current_level = root;
    
    scanf("%d %d\n", &num_of_lines, &num_of_queries);

    //input and parse HRML
    for (int i = 0; i < num_of_lines; i++) {
        string hrml;
        
        getline(cin, hrml);
        
        HrmlParse(hrml, current_level);
    }
    
    //query input
    for (int i = 0; i < num_of_queries; i++) {  
        string query;
        int j = 0;
        int mark = 0;
              
        getline(cin, query);
        
        //first tag compare
        while(query[j] != '.' && query[j] != '~') j++;
        if (current_level->tag != query.substr(mark, j)) {
            cout << current_level->tag;
            
            printf("Not Found!1\n");
            continue;
        }
        
        mark = j++;
        
        //another tags compare
        while(query[j] != '~') {
            j++;
            
            if(query[j] != '.') {
                int num_children = current_level->children.size();
                int k = 0;
                bool correctTag = false;
                
                for (; k < num_children; k++) {
                    if (current_level->children.at(k)->tag == query.substr(mark, j-mark)) {
                        current_level = current_level->children.at(k);
                        correctTag = true;
                        break;
                    }
                }
                
                if (!correctTag) {
                    printf("Not Found!2\n");
                    break;
                }
                
                mark = j + 1;
            }
        }
        
        //compare attribute
        int num_attribute = current_level->attributes.size();
        bool correctAtr = false;
        
        for (int k = 0; k < num_attribute; k++) {
            if (query.substr(mark, query.size()-mark) == current_level->attributes.at(k)) {
                cout << current_level->values.at(k) << endl;
                correctAtr = true;
                break;
            }
        }
        
        if (!correctAtr) {
            printf("Not Found!3\n");
        }
    }
    
    return 0;
}
