#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int startTime;
    int duration;
    int endTime;
};

struct Available_Workshops {
    int n;
    struct Workshop* arrWs;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    static struct Available_Workshops result = {n, new struct Workshop[n]};
    
    for(int i=0; i<n; i++) {
        result.arrWs[i].startTime = start_time[i];
        result.arrWs[i].duration = duration[i];
        result.arrWs[i].endTime = start_time[i] + duration[i];
    }
    
    return &result;
}

// need to optimize
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int currentTime = 0;
    int result = 0;
    
    for (int i=0; i < (ptr->n)-1; i++) {    // sort by endTime
        for (int j=i+1; j < ptr->n; j++) {
            struct Workshop tmp;
            if (ptr->arrWs[i].endTime > ptr->arrWs[j].endTime) {
                tmp = ptr->arrWs[i];
                ptr->arrWs[i] = ptr->arrWs[j];
                ptr->arrWs[j] = tmp;
            }
        }
    }
    
    for (int i=0; i < ptr->n; i++) {
        if (currentTime <= ptr->arrWs[i].startTime) {
            currentTime = ptr->arrWs[i].endTime;
            result++;
        }
    }
    
    return result;
}

// Fixed
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
