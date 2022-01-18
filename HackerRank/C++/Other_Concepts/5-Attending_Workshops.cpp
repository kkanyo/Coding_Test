#include<bits/stdc++.h>

using namespace std;

#include<algorithm>

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int startTime;
    int duration;
    int endTime;
public:
    // Overloading operator '<' for sorting by end time.
    bool operator<(Workshop ws2) {
        if (this->endTime < ws2.endTime) { return true; }
        else return false;
    }
};

struct Available_Workshops {
    int n;                  // The number of workshops
    Workshop* arrWs; // Array of Workshop
};

// Initializes its elements
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* result = new Available_Workshops;
    *result = {n, new Workshop[n]};
    
    for(int i=0; i<n; i++) {
        result->arrWs[i].startTime = start_time[i];
        result->arrWs[i].duration = duration[i];
        result->arrWs[i].endTime = start_time[i] + duration[i];
    }
    
    return result;
}



// Returns the maximum number of workshops the student can attend without overlap
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int currentTime = 0;
    int result = 0;
    
    /*
    * Fast end time of workshop mean
    * its start time is fast and duration is short.
    * So, need to sort by end time.
    * (Task scheduling, earliest finish time first)
    */
    sort(ptr->arrWs, ptr->arrWs+ptr->n);
    
    for (int i=0; i < ptr->n; i++) {
        if (currentTime <= ptr->arrWs[i].startTime) {   // Pass the workshop already start
            currentTime = ptr->arrWs[i].endTime;        // Upadate 'currentTime' to end time of workshop attended
            result++;
        }
    }
    
    return result;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
