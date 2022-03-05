// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

typedef pair<int,int>  vp;
class Solution{
    
    public:
    int distinctIds(int arr[], int n, int m)
    {
        // Complete this function
        priority_queue<vp,vector<vp>,greater<vp> > pq;
        int i=0;
        unordered_map<int,int>M;
        for(;i<n;i++){
            M[arr[i]]++;
            
        }
        for(auto i : M ){
            pq.push({i.second,i.first});
            
        }
        if(n<m) return 0; //edge case
        while(pq.size()  and m--){
            auto top =pq.top(); pq.pop();
            int cnt=top.first,val=top.second;
            // cout<<cnt<<" "<<val<<endl;
            cnt--;
            if(cnt<1)  continue;
            pq.push({cnt,val});
        }
        return pq.size();
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
          cin>>arr[i];
        }
    
    	int m ;
    	cin >> m;
        Solution ob;
    	cout << ob.distinctIds(arr, n, m) << endl;
    }
	return 0;
}  // } Driver Code Ends