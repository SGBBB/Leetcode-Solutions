class Solution {
    int visited[201]={};
    vector<int> adj[201];
    void dfs(int node){
        visited[node]=1;
        for(auto it:adj[node])
            if(!visited[it])
                dfs(it),visited[it]=1;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        /*
        I have n number of nodes
        
        */
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(i!=j and isConnected[i][j])
                    adj[i].push_back(j);  
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            if(!visited[i])
                cnt++,dfs(i );
        return cnt;
        
        
        
    }
};