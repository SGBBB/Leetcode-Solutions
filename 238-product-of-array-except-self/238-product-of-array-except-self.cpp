class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int i=0,temp=1;
        for(;i<n;i++){
            //logic
            ans[i]=temp,temp*=nums[i];
        }
        for(i=n-1,temp=1;i>=0;i--){
            ans[i]*=temp,temp*=nums[i];
        }
        return ans;
    }
};