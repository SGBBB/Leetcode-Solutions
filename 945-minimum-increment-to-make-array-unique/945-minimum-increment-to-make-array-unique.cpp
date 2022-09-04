class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minSteps=0,curNum=nums[0],n=nums.size();
        for(int i=0;i<n;i++){
            
            minSteps+=max({0,curNum-nums[i]});
            curNum=max({curNum+1,nums[i]+1});
        }
        return minSteps;
    }
};
/*
1 1 2 2 3 7
1 * 2 * 3 7
*/