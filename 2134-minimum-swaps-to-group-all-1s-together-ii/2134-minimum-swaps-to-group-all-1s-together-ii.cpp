class Solution {
public:
    int minSwaps(vector<int>& nums) {
//         int ones_count=0,len=nums.size();
//         for(int i:nums) ones_count+=i;
//         if(!ones_count or ones_count==len) return 0;
//         int i=0,j=0;
//         int curr_ones_count=0
//         for(j;j<ones_count;j++){
//             curr_ones_count+=nums[j];
//         }
//         int ans=ones_count-curr_ones_count;
//         for(;j<len;j++){
//             ans=min();
//         }
        
        
//         return ;
        
        int ones = count(begin(nums), end(nums), 1), n = nums.size(), res = n;
        int i = 0, j = 0, cnt = 0;
        for(;j<ones;j++)  cnt+=nums[j],res=min(res,ones-cnt); 
        cout<<res<<endl;
    for (; i < n; ++i) {
        // while (j - i < ones)
        cnt += nums[j++ % n];
        cnt -= nums[i];
        res = min(res, ones - cnt);
        
    }
    return res;
    }
};