// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
    int countHandshakes(int N,vector<int> &dp){
        
        int ways=0;
        if(dp[N]) return dp[N];
        if(N==0 || N==2) return dp[N]=1;
        
        for(int i=0;i<N;i+=2){
            ways+=countHandshakes(i,dp)*countHandshakes(N-i-2,dp);
        }
        return dp[N]=ways;
    }
public:
    int count(int N){
        vector<int> dp(N+1,0);
        dp[0]=1;
        // for(int i=2;i<N+1;i+=2){
        //     for(int j=0;j<i;j+=2)
        //         dp[i]=dp[i]*dp[N-i-2];
        // }
        // return dp[N];
        return countHandshakes(N,dp);
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