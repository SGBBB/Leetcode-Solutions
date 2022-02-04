class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_len=0,i=0,n=nums.size(),sum=0;
        unordered_map<int,int>M;
        for(;i<n;i++){
            sum+=(nums[i]) ?1:-1;
            if(!sum) max_len=i+1;
            if(M.count(sum)) {
                max_len=max(max_len,i-M[sum]);
            }
            else M[sum]=i;
        }
       return max_len;
    }
};