using ll=long long;
class Solution {
    vector<uint> dp;
public:
    /*
    0  1   2    3    4     <-targets
    1  1   2    3    7
    
    
       1    2   3 <-elements
    0  
    1  1     
    2  2
    3  1
    4
    
    
    */
    int combinationSum4(vector<int>& nums, int target ){
        dp.resize(target+1,1);
        int n=nums.size();
        for(int i=1;i<=target;i++){
            dp[i]=0;
            for(int j=0;j<n;j++){
                if(nums[j]<=i)
                    dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[target];
        // return combinationSum4Helper(nums,target  );
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