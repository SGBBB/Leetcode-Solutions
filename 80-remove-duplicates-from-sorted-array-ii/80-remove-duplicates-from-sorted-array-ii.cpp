class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int val=nums.front(),cnt=0,ans=0,n=nums.size(),idx=0;
        for(int n:nums){
            if(idx<2 or n!=nums[idx-2])nums[idx++]=n;
        }
        return idx;
    }
};