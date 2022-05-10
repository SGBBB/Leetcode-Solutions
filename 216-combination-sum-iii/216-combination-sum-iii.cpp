class Solution {
    void dfs(int k,int n, vector<vector<int>> &ans,int idx=1,vector<int> arr={}){
        if( n>= 0 && k>=0 ){
            if( !n && !k ){
                ans.push_back(arr);  
                return;
            }
            for(int start=idx;start<10;start++){
                if(start>n) return;
                // if( start==idx  ){
                    arr.push_back(start);
                    dfs(k-1,n-start,ans,start+1,arr);
                    arr.pop_back();
                // }
            }
            
        }
    }
public:
    vector<vector<int>> combinationSum3( int k, int n ) {
        vector<vector<int>> ans;
        dfs(k,n,ans);
        return ans;
    }
};