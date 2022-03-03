class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int  n=nums.size(),cnt=0,i=0;
        if(n<3) return 0;
        vector<int> dp(nums.size()+1);
        int td=nums[1]-nums[0];
        for(i=2;i<n;i++){ int d=nums[i]-nums[i-1];
            if (td==d)dp[i]= dp[i-1]+1;  
            else {dp[i]=0;td=d;}
        }
        int ans= accumulate(dp.begin(),dp.end(),0);
        
        return ans;
    }
};