// long dp[10005][2];
class Solution {
    int calMaxProfit(vector<vector<int>> &dp,vector<int>& prices,int idx,bool canBuyStock=1){
        int maxProfit=0;
        if(dp[idx][canBuyStock]!=-1) return dp[idx][canBuyStock];
        if( idx<prices.size() ){
            
            if(canBuyStock ){
                int buyStock= -prices[idx]+  calMaxProfit(dp,prices,idx+1,0) ;
                int dontBuyStock=0+calMaxProfit(dp,prices,idx+1,1);
                maxProfit=max( {buyStock,dontBuyStock} );
            }
            else{
                int sellStock= prices[idx]+  calMaxProfit(dp,prices,idx+1,1) ;
                int dontSellStock=0+calMaxProfit(dp,prices,idx+1,0);
                //you havent sold stock yet so passing 0 means that you cant buy stockin next idx
                maxProfit=max( {sellStock,dontSellStock} );
            
            }
        } 
        return dp[idx][canBuyStock]=(idx==prices.size() )? 0:maxProfit; 
        //if i have reached end of price array then i cant make choice
    }
public:
    int maxProfit(vector<int>& prices) {
        // memset(dp,-1,sizeof dp);
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return calMaxProfit( dp,prices,0);
    }
};