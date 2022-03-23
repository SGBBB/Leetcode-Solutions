// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans = arr[n-1] - arr[0]; //initially after sorting tallest tower = arr[n-1] and smallest tower = arr[0]
        
        int smallest = arr[0] + k; //we have to increase smallest tower by k
        int tallest = arr[n-1] - k; //we have to decrease tallest tower by k
        
        int mini,maxi;
        
        for(int i = 0; i < n-1; i++) { 
            mini = min(smallest, arr[i+1] - k); //minimum right tower 
            maxi = max(tallest, arr[i] + k); //maximum left tower ,if you found greater maxi and difference went down so dont consider it
            // cout<<" maxi and mini are "<<mini<<" "<<maxi<<endl;
            if(mini < 0) continue;
            // cout<<   mini<<" "<<maxi << endl;
            //If diff. btw maxi and mini is too huge then don't consider it !
            ans = min(ans, maxi - mini);
        }
        /*
        Try this test case
        
        */
        return ans;
    }
};

/*


*/


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends