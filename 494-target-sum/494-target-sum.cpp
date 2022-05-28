class Solution {
public:
    int f(vector<vector<int>> &dp,vector<int> &nums, int t,int i,int temp){
    if(i==0 ){
        cout<<(temp+nums[i]==t)<<" "<<(temp-nums[i]==t)<<endl;
        // return (t==temp); 
        return dp[i][temp+1000]= (temp+nums[i]==t) + (temp-nums[i]==t);
        
    }
        
        
    if(dp[i][temp+1000]>-1e8) return dp[i][temp+1000];
    // cout<<temp<<endl;
    int ans=0;
    ans=f(dp,nums,t,i-1,temp+nums[i])+f(dp,nums,t,i-1,temp-nums[i]);  //dp[i][]=
    return dp[i][temp+1000]=ans;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();        
        vector<vector<int>> dp(21,vector<int>(2001,-1e8) );      
        return f(dp,nums,target,nums.size()-1,0);
    }
};