class Solution {
    
    vector<int> nums;
    int k,n;
    int dfs(int i=0){
        if(i>=n-1){
            return nums[i];
        }
        int maxScore=  -1e8;
        
        
        for(int j=i+1;j<=min({i+k ,n-1});j++){
            maxScore=max({maxScore,nums[i]+dfs(j)});
            // cout<<maxScore<<" "<<i<<endl;
        }
        return maxScore;
    }
public:
    int maxResult(vector<int>& nums, int k) {
        /*
        
        
        */
        this->nums=nums,
        this->k=k;
        n=this->nums.size();
        int dp[n];
        // return dfs();
        deque<int> dq;
        dp[0]=nums[0];
        dq.push_back(dp[0]);
        // Lets iteratre until <= k-1
        int i=1,j=0;
        while(i<=min(k-1,n-1)){
            dp[i]=nums[i]+dq.front();
            // saare chotte elemets ko pop karo
            while(!dq.empty() && dp[i]>dq.back())
                dq.pop_back();
            
            dq.push_back(dp[i]);
            
            i++;
        }
        while(i<n){
            dp[i]=nums[i]+dq.front();
            if(dp[j]==dq.front() )
                dq.pop_front();
            while(!dq.empty() && dp[i]>dq.back())
                dq.pop_back();
            dq.push_back(dp[i]);
            j++,i++;
        }
        return dp[n-1];
    }
};