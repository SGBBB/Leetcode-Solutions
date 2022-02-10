class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        int cnt=0,idx=0,sum=0;
        for(int i:nums){
            sum+=i;
            cnt+=(sum==k);
            cnt+=M[sum-k];
            M[sum]++;
            
            
        }
        return cnt;
    }
};