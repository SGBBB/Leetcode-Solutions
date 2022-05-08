class Solution {
public:
    int countTexts(string pressedKeys) {
        long mod=1e9+7;
        int n=pressedKeys.size();
        // cout<<pressedKeys.size()<<endl;
        long dp[n+1];
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            char ch=pressedKeys[i-1];
            //whether its equal to previous char or not dp[i] has state influence  of dp[i-1]
            dp[i]=dp[i-1];
            

//         
        // now checking if current char ==pressedKeys[i-2] 
        if(i>=2 && ch==pressedKeys[i-2]){
            dp[i]=(dp[i]+dp[i-2])%mod;
            // Further conditions will only be checked only if ch==pressedKeys[i-2]
            // now checking if current char ==pressedKeys[i-3]
            if(i>=3 && ch==pressedKeys[i-3]){
                dp[i]=(dp[i]+dp[i-3])%mod;
                // now checking if current char ==pressedKeys[i-4] 
                if(i>=4 && ch==pressedKeys[i-4] && (ch=='7' || ch=='9') )
                    dp[i]=(dp[i]+dp[i-4])%mod;
            }
        }
        }
        for(int i=0;i<=n;i++)
            cout<< dp[i]<<" ";
        return (int)dp[n]%mod;
        //time complexity is 4*O(n)
        
    }
};