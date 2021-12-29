#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    public:
        LRUCache(int c) { this->cp = c; }
        void set(int k, int val) {
            Node* new_node = new Node(k, val);
            
            if (head == NULL) {
                head = new_node;
                tail = new_node;
            }
            else {
                head->prev = new_node;
                new_node->next = head;
                head = new_node;
            }
            
            if (mp.count(k) > 0) {    //If already have that key             
                mp[k]->value = val;
                MoveToHead(mp[k]);
                
                return;       
            }
            
            if (mp.size() >= cp) {      //If map is fulled
                mp.erase(tail->key);
                
                Node* tmp = tail;   //delete tail
                tail = tail->prev;
                delete(tmp);
                tail->next = NULL;
            }
            mp.insert(make_pair(k, new_node));
        }
        int get(int k) {
            if (mp.count(k) > 0) { 
                MoveToHead(mp[k]);
                
                return mp[k]->value; 
            }
            else { return -1; }
        }
    private:
        void MoveToHead(Node* node) {
            head->prev = node;
            if (node->prev) { node->prev->next = node->next; }
            if (node->next) { node->next->prev = node->prev; }
            node->prev = NULL;
            node->next = head;
            head = node;
        }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
