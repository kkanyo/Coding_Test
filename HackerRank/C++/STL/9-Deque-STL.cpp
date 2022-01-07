#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> subArr;
    int numSubArr = n-k+1;
    int max = 0;
    int i = 0;
    
    while (i < k-1) {
        subArr.push_back(arr[i++]);
    }
    
    while (i < n) {
        subArr.push_back(arr[i++]);

        for (auto j : subArr) {         //O(n^2), Not effective
            if (j > max) { max = j; }
        }
        cout << max << " ";
        
        max = 0;
        subArr.pop_front();
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
