class Solution {
    int find_target(int i,int j,int target,vector<int> &nums){
        if(i<=j){
            int mid=(i+j)>>1;
            if(target==nums[mid]) return  mid;
            return (target>nums[mid]) ? find_target(mid+1,j,target,nums): 
                find_target(i,mid-1,target,nums) ;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return find_target(0,n-1,target,nums);
    }
};