class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof dp);
        dp[0]=nums[0];//Im at begining so these is only 1 way to steal and go
        
        // for(int i=1;i<n;i++){
        //     int take=nums[i];
        //     //taking the steal gathered until last alternate house
        //     if(i>1) take+=dp[i-2];
        //     int notTake=dp[i-1];
        //     dp[i]=max(take,notTake);
        // }
        
        
        //Space optimised solution aka most optimised solution in this planet
        int prev2=0,prev=nums[0],cur;
        for(int i=1;i<n;i++){
            int take=nums[i];
            // taking the steal gathered until last alternate house
            take+=prev2;
            int notTake=prev;
            cur=max(take,notTake);
            prev2=prev,
            prev=cur;
        }
        
        return  prev;
    }
};
/*
1 2 3 1
1 2 4 4

take=nums[i]+dp[i];
if(i>1) take+=dp[i-2];
notTake=dp[i-1];
dp[i]=max(take,notTake);
*/