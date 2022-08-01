class Solution {
public:
    int uniquePaths(int m, int n) {
       // vector<vector<int>>  dp(m,vector<int>(n,1));
        vector<int> pre(n,1),cur(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                cur [j]=pre[j]+cur[j-1];
            pre=cur;
        }
            
        return pre[n-1];
    }
    /*
    
    1 1 
    1 2
    1 3
    
    */
};