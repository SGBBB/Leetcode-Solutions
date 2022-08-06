
class Solution {
    vector<int> dp;
public:
    int combinationSum4(vector<int>& nums, int target ){
        dp.resize(target+1,-1);
        return combinationSum4Helper(nums,target  );
    }
    int combinationSum4Helper(vector<int>& nums, int target) {
        //if target is 0 then return 0;
        if(target==0) 
            return 1;
            
        //If we have already found target then return the saved answer
        
        if(dp[target]!=-1)
            return dp[target];
        int len=nums.size(),
        totalCombinations=0;
        
            for(int i=0;i<len;i++)
                if(nums[i]<=target)
                    totalCombinations+=combinationSum4Helper( nums,target-nums[i] );
        
        return dp[target]=totalCombinations;
    }
};