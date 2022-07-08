int dp[101][24][101]={0}; // m ,prevColor , target
class Solution {
    vector<int> houses;
    vector<vector<int>> cost;
    int dfs(int target,int idx=0,int prevColor=-1){
        int m=houses.size(),
            n=cost[0].size();
        if(target<0)
            return 1e8;
        
        if(idx==m){
            if(!target)
                return 0;
            return 1e8;
        }
        // Now idx<m-1
        int globalMinCost=1e8;
        if(dp[idx][prevColor+1][target]>0)
            return dp[idx][prevColor+1][target];
        
        
        //if current house is already colored
        if(houses[idx]!=0 ){
            int curColor=houses[idx];
            if(prevColor==-1 || prevColor!=curColor)
                target=target-1;
            return dfs(target,idx+1,curColor);
             
        }
        // right now curHouse isn't colored
        //Trying all n colors
        for(int i=0;i<n;i++){
            int curColor=i+1;
            int nextTarget=target;
            if( prevColor==-1 || prevColor!=curColor )
                nextTarget=nextTarget-1;
            int curMinCost=cost[idx][i]+dfs(nextTarget,idx+1,curColor);
            // cout<<curMinCost<<endl;
            globalMinCost=min({globalMinCost,curMinCost});
        }
        return dp[idx][prevColor+1][target]=globalMinCost;
        
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        /*
        [1,10]
        [10,1]
        [10,1] 
        [1,10] 
        [5,1]
        
        Parameters:
        target  target
        color choice 1-n
        choice of houseidx of house
        
        if house is already painted then do nothing
        */
        memset(dp,0,sizeof dp);
        this->houses=houses,
        this->cost=cost;
        int response= dfs(target);
        if(response==1e8)
            return -1;
        return response;
    }
};