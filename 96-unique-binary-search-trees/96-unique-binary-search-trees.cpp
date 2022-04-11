int dp[20] ;
class Solution {
    
    int cntTrees(int n){
        if(dp[n]!=-1) return dp[n];
        int cnt=0;
        for(int k=1;k<n+1;k++){
            cnt+=cntTrees(k-1) * cntTrees(n-k);
        }
        return dp[n]=cnt;
    }
public:
    int numTrees(int n) {
        for(int i=0;i<n+1;i++) dp[i]=-1;
        dp[0]=1;//base case
        cntTrees(n);
        for(int i=0;i<n+1;i++) cout<<dp[i]<<" ";
        return dp[n];
    }
};
/*

Try considering every ndoe as root 
apply partition dp on left and right subtreee
time complexity is  n^2. 
*/