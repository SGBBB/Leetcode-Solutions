int dp[2001][2001];
class Solution {
    int f(int idx,int k,vector<vector<int>>& piles ){
        int n=piles.size();
        if(idx==n || !k) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int exclude_pile=0,include_pile=0,maxi=0;
        maxi=f(idx+1,k , piles);
        int cnt=0,sz=sz=piles[idx].size();
        for(int i=0;i<min(sz,k);i++){
            
            include_pile+=piles[idx][i]; cnt++;
            // cout<<exclude_pile<<" "<<include_pile<< "  "<<
            //     f(idx+1,k-(i+1),piles)<<" "<<idx<<" k is "<<k<<i<<cnt<<endl;
            maxi=max(maxi,include_pile+f(idx+1,k-(i+1),piles) );
        }
        
        return dp[idx][k]=maxi;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof dp);
        return f(0,k,piles);
    }
};