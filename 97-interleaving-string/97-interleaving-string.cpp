class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        /*
        
        aabcc dbbca
        aadbbbaccc
        */
        int n1=s1.size(),n2=s2.size();
        int dp[n2+1][n1+1] ;
        if(n1+n2!=s3.size())
            return 0;
        //When both are empty so its a positive case
        dp[0][0]=1;
        //Filling first row
        for(int i=1;i<=n1;i++)
            dp[0][i]=dp[0][i-1]&&s1[i-1]==s3[i-1];
        //Filling first col
        for(int i=1;i<=n2;i++)
            dp[i][0]=dp[i-1][0]&&s2[i-1]==s3[i-1];
        
        for(int i=1;i<=n2;i++){
            for(int j=1;j<=n1;j++){
                bool isS1Equal= dp[i][j-1]&&s1[j-1]==s3[i+j-1],
                     isS2Equal= dp[i-1][j]&&s2[i-1]==s3[i+j-1];
                dp[i][j]=isS1Equal || isS2Equal;
            }
        }
        for(int i=0;i<n2+1;i++){
            for(int j=0;j<n1+1;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[n2][n1];
        
    }
};