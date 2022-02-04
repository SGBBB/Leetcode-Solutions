bool cmp(long long a,long long b){
    return a>b;
}

class Solution {
    int mod=1e9 +7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        long long n=nums.size(),i=0,mod=1e9+7;
        vector<long long> cnt(n);
        for(auto j:requests) {
            cnt[j[0]]++;
            if(j[1]<n-1) cnt[j[1]+1]--; 
        }
        for(i=1;i<n;i++){
            cnt[i]+=cnt[i-1];
        }
        sort(cnt.begin(),cnt.end(),cmp);
        sort(nums.begin(),nums.end() ,cmp);
        long long sum=0;
        for(i=0;i<n;i++){
            sum=( (sum%mod) + (((nums[i]%mod) * (cnt[i]%mod))%mod))%mod;
        }
        return sum%mod;
    }
};