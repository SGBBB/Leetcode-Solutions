class Solution {
    int dp[100001];
    int recursion(int n){
        if(!n or n==1 ) return dp[n]=n;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            if(!recursion(n-i*i))
                return dp[n]=true;
        }
        return dp[n]=false;
    }
public:
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof dp);
        return recursion(n);
        
    }
};