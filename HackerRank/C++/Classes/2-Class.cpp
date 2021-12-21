/*
If you want to erase string of stringstream, use stringstream.str("") or stringstream.str(string())
clear() is used to eliminate error state in stream 
*/

#include <iostream>
#include <sstream>
using namespace std;

class Student {
    private:
        int age;
        string first_name;
        string last_name;
        int standard;
    public:
        int get_age() {
            return age;
        }
        string get_first_name() {
            return first_name;
        }
        string get_last_name() {
            return last_name;
        }
        int get_standard() {
            return standard;
        }
        void set_age(int num) {
            age = num;
        }
        void set_first_name(string str) {
            first_name = str;
        }
        void set_last_name(string str) {
            last_name = str;
        }
        void set_standard(int num) {
            standard = num;
        }
        string to_string() {
            string result;
            stringstream ss;
            
            ss << age;
            result = ss.str() + "," + first_name + "," + last_name + ",";
            ss.str("");     //for clearing ss (stringstream)
            ss << standard;
            result += ss.str();
            
            return result;
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}