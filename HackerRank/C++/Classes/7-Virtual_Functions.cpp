#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Only Edit Here
//----------------------------------------
int p_id = 0;   //professor id
int s_id = 0;   //student id

class Person {
    private:
        string name;
        int age;
    public:
        virtual void getdata() {
            cin >> name >> age;
        }
        virtual void putdata() {
            cout << name << " " << age;
        }
        virtual ~Person();
};

class Professor : public Person{
    private:
        int publications;
        int cur_id;
    public:
        Professor() { cur_id = ++p_id; }
        void getdata () {
            Person::getdata();
            cin >> publications;
        }
        void putdata() {
            Person::putdata();
            cout << " " << publications << " " << cur_id << '\n';
        }
};

class Student : public Person{
    private:
        int marks[6];
        int cur_id;
    public:
        Student() { cur_id = ++s_id; }
        void getdata() {
            Person::getdata();
            for (int i = 0; i < 6; i++) {
                cin >> marks[i];
            }
        }
        void putdata() {
            int sum_marks = 0;
            for (int i = 0; i < 6; i++) {
                sum_marks += marks[i];
            }
            Person::putdata();
            cout << " " << sum_marks << " " << cur_id << '\n';
        }
};
//--------------------------------------

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
