class Solution {
public:
    bool isMatch(string s, string p) {
        //Most optimised solution in this planet
        int n1=s.size(),n2=p.size();
        // bool dp[n1+1][n2+1];
        //prev is initially 0th row
        vector<bool>  prev(n1+1,0);
        // memset(dp,false,sizeof(dp));        
        prev[0]=true;
        for(int i=1;i<=n2 && p[i-1]=='*' ;i++)prev[i]=true;
        for(int i=1;i<n1+1;i++){
            vector<bool>cur(n2+1,0);
            //These calculatations are being  made row-wise
            for(int j=1;j<n2+1;j++){
                if(p[j-1]=='?' || p[j-1]==s[i-1]) {
                    cur[j]=prev[j-1];
                }
                else if(p[j-1]=='*') {
                   cur[j]=prev[j] or cur[j-1]; 
                }
                /*else case: characters are unequal*/
                 
                
            }
            prev=cur;
        }
        // for(int i=0;i<n1 + 1;i++){
        //         for(int j=0;j<n2+1;j++) cout<<dp[i][j]<<" ";
        //         cout<<endl;
        // }
        return prev[n2];
        
        
    
        
    }
};