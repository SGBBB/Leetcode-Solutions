class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long i=0,len=prices.size(),ans=0;
        for(;i<len;){
            long long cnt=1;
            i++;
            for(;i <len and prices[i]==prices[i-1]-1;cnt++,i++){ }
            ans+=( (cnt*(cnt+1))/2);
        }
        return ans;
    }
};