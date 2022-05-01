// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
    int countWays(int N,vector<int> &dp){
        if(dp[N] ) return dp[N];
        int cnt=0;
        for(int i=0;i<N;i+=2){
            cnt+=countWays(i,dp)*countWays(N-i-2,dp);
        }
        return dp[N]=cnt;
    }
public:
    int count(int N){
        vector<int> dp(N+1); 
        fill(dp.begin(),dp.end(),0);
        dp[0]=1;
        
        return countWays(N,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends