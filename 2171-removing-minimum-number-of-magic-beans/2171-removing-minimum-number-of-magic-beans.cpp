class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(),beans.end());
        long long min_removals=LLONG_MAX,idx=0,
        n=beans.size() ,sum=0;
        for(int i:beans) sum+=i;
        for(int i:beans){
            min_removals=min( min_removals  ,
                             sum-(1LL*(n-idx)*i) );
            idx++;
        }
        return min_removals;
    }
};