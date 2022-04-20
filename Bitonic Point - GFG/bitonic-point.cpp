// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    int l=0,h=n-1;
	    while(l<h){
	        int mid=(l+h)>>1;//cout<<"mid is "<<mid<<endl;
	        if(arr[mid]>arr[mid+1] ){
	            h=mid;
	        }
	        else{
	            l=mid+1;
	        }
	    }
	    return arr[l];
	}
};

/*
Simply understand that im concerned abput finding the peak from where values are decreasing.
1 45 47 15 12 10 8 7

potential ansss 15
 
1 3 1

1 45 47 50 5

*/

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends