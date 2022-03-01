class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        if(n>0)
        ans[1]=1;
        for(int i=2;i<n+1;i++){
            ans[i]=!(i & 1 ) ? ans[i/2]: ans[i/2]+1;
        }
        return ans;
    }
};