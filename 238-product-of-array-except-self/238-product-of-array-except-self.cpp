class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n),prefix(n,1),suffix(n,1);
        int temp=1;
        for( auto i=n-1;i>-1;i--) temp*=nums[i],suffix[i]=temp;
        temp=1;
        for(int i=0;i<n;i++) {
            temp*=nums[i];
            prefix[i]=temp;
            if(!i){
                ans[i]=suffix[i+1];
            }
            else if (i==n-1){
                ans[i]=prefix[i-1];
            }
            else
            ans[i]=suffix[i+1]*prefix[i-1];
        }
        return ans;
    }
};