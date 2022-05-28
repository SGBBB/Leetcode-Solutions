int dp[600][101][101];
class Solution {
    int dfs(vector<vector<int>> &arr,int m,int n,int idx){
        int sz=arr.size();
        if( m <0 || n <0 )
            return -1e8;
        if(!idx){ //base case
            if( m-arr[0][0]>=0 && n-arr[0][1]>=0)
                return 1;
            return 0;
        }
        if(dp[idx][m][n]>-1 )
            return dp[idx][m][n];
        int maxi=0;
        if(idx<sz){
            
            int take=
                dfs(arr,m-arr[idx][0],n-arr[idx][1],idx-1)+ 1,
            
                notTake=dfs(arr,m,n,idx-1)+0;
            maxi=max({maxi,take,notTake});
            
            
        }
        return dp[idx][m][n]=maxi;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*
        How should I proceed with this problem??
        "10"    "0001"    "111001"    "1"    "0"
        11       31          24        01     10
        
        pass the idx=n-1
        
        
        
        */
        vector<vector<int>> arr;
        for(auto str:strs){
            int cnt0=0,cnt1=0;
            for(auto ch:str)
                cnt0+=ch=='0',  cnt1+=ch=='1';
            
            arr.push_back({cnt0,cnt1}); 
        }
        memset(dp,-1,sizeof dp);
        return dfs(arr,m,n,arr.size()-1);
        
    }
};