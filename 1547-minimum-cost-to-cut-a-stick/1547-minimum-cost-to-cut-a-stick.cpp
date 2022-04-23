int dp[101][101];
class Solution {
    int dfs(int i,int j,vector<int> &cuts){ 
        //some base case
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            // int pivot=cuts[k];
 int cost=dfs(i,k-1,cuts)+(cuts[j+1]-cuts[i-1])+dfs(k+1,j,cuts);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        /*
We are sorting the given partitions so that  sequence is maintained
and while partitioning we can easily be able to divide a problems into 2 seperate subproblems   
        */
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof dp);
        return dfs( 1,cuts.size()-2,cuts );
        
    }
};


/*
3  5  1  4 
score earned: 7
03 37


*/
