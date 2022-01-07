#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> subArr;
    int max = arr[0];
    int i = 0;      //start point of subarray on 'arr'
    
    while (i < k) {                             //create first 'subArr' and search maximum integer
        if (arr[i] > max) { max = arr[i]; }
        subArr.push_back(arr[i++]);
    }
    cout << max << " ";
    
    while (i < n) {                     //move range of 'subArr'
        int head = subArr[0];           //save integer taht will go out of range
        subArr.push_back(arr[i++]);
        subArr.pop_front();

        if (subArr[k-1] > max) { max = subArr[k-1]; }   //update 'max'

        if (head == max) {                  //If integer out of range is same to 'max'
            max = subArr[0];                //initialize 'max'
            for (auto j : subArr) {         //re-search maximum integer
                if (j > max) { max = j; }
            }
        }
        cout << max << " ";   
    }
    cout << "\n";
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
