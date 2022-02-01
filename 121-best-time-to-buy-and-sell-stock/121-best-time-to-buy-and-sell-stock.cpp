class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        vector<int> dp(len);
        
        int i=len-2,sell_day=prices[len-1];
        for(;i>-1;i--){
            dp[i]=max(dp[i+1],sell_day-prices[i]);
            sell_day=max(sell_day,prices[i]);
        }
        return dp[0];
    }
};