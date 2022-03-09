class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len=0;
        set<long > s(nums.begin(),nums.end());
        int cnt=1;
        long prev=LONG_MIN;
        for(auto i:s){
            cnt=(i==prev+1)? cnt+1:1  , prev=i , max_len=max(cnt,max_len);
        }
        return max_len;
    }
};