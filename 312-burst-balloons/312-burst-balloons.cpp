int dp[302][302];
class Solution {
    int countCoins(int i,int j,vector<int>& values){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=0;
        for(int k=i;k<=j;k++){
            int coins=values[i-1]*values[k]*values[j+1];
            coins+=countCoins(i,k-1,values)+countCoins(k+1,j,values);
            dp[i][j]=max(dp[i][j],coins);
        }
        return dp[i][j];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp,-1,sizeof dp);
        return countCoins(1,nums.size()-2,nums);
    }
};