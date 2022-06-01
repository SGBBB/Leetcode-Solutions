int dp[2001][2001];
class Solution {
    int findMaxValue( int k,vector<vector<int>>& piles ,int idx=0 ){
        int n=piles.size();
        
         if(idx<0 || k<1)
             return 0;
        //Now I have k>1
        if(dp[idx][k]>-1) 
            return dp[idx][k];
//I'll try to pick coin from top of every pile so everytime Im having n choices
        int sum=0;
        int len=min( k,(int)piles[idx].size() );
        int include=0,
            exclude=findMaxValue(k,piles,idx-1);// skipping the current pile
        for(int i=0;i<len;i++){
             
            
            int topCoinValue=piles[idx][i];
            sum+=topCoinValue;
            //Calling funciton to perform recursion
            include=max( {include , sum+findMaxValue( k-i-1,piles,idx-1 )} )  ;
            
             
        }
        return dp[idx][k]=max(include,exclude);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof dp);
        return findMaxValue( k,piles,piles.size()-1);
    }
};