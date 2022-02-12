class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0,j=0,len=nums.size(),sum=0,curr_sum=0,max_len=-1;
        for(int i:nums) sum+=i;
        sum=sum-x;
        if(!sum ) return len;
        unordered_map<int,int> M;
        
        for(;j<len;j++){
            curr_sum+=nums[j];
            if(curr_sum==sum) max_len=max(max_len,j+1);
            if(M.count(curr_sum-sum) )
                max_len=max(max_len,j-M[curr_sum-sum]);
            M[curr_sum]=j;
            
        }
        return (max_len==-1) ? -1  : len-max_len;
    }
};