class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size(),l=0,h=n-1;
        for(;l<=h;){
            int mid=(l+h)>>1;
            cout<<nums[mid]<<endl;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[h]) h--;
            else if(nums[mid]<nums[h] ){
                if(target>nums[mid] && target<=nums[h]) l=mid+1;
                else h=mid-1;
            }
            else {
                if(target>=nums[l] && target<nums[mid] ) h=mid-1;
                else l=mid+1;
            }
        }
        return false;
    }
};