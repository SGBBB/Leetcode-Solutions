class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long i=0,len=prices.size(),ans=0;
        for(;i<len;i++){
            long long cnt=1;
            for(;i+1 <len and prices[i+1]==prices[i]-1;cnt++,i++){ }
            ans+=( (cnt*(cnt+1))/2);
        }
        return ans;
    }
};