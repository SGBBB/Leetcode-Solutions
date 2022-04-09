// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        /*
        Let me devise an algo to cater this logic
        if i met a sum again then do cnt++;
        */
        ll cnt=0,sum=0;
        unordered_map<ll,ll> M;
        for(int num:arr){
            sum+=num;
            if(!sum) cnt++;
            cnt+=M[sum];
            M[sum]++;
        }
        return cnt;
    }
};

/*
6 -1 -3 4 -2 2 4 6 -12 -7

6

*/


// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends