// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int longest(int arr[],int n)
    {
        // Write your code here
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!ans.empty() and arr[ans.back()]>arr[i] )continue;
            ans.push_back(i);
        }
        return ans.size();
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i, arr[n+5];
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution ob;
        cout<<ob.longest( arr, n )<<endl;
    }
    return 0;
}  // } Driver Code Ends