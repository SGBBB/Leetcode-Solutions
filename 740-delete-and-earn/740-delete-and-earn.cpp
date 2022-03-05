class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int cnt[10002]={0},dp[10002]={0} ;
        for(int i:nums) cnt[i]++;
        cout<<cnt[1]<<" "<<cnt[2]<<endl;
        dp[1]=cnt[1];
        for(int i=2;i<10001;i++){
            // if(i==2) 
            dp[i]=max(dp[i-1] , (i*cnt[i])+dp[i-2]);
            if(i<6)
            cout<<"  bhj "<<dp[i]<<endl;
        }
        
        return dp[10000];
    }
};