class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long n=questions.size();
        vector<long long> ans(n);
        
        ans[n-1]=questions[n-1][0];
        long long  i=n-2;
        for(;i>-1;i--){
            long long max_after_skip=(i+questions[i][1]+1)>n-1 ?0:ans[i+questions[i][1]+1] ;
            ans[i]=max(questions[i][0]+max_after_skip,
                     ans[i+1]
                      );
        }
        return ans.front();
    }
};