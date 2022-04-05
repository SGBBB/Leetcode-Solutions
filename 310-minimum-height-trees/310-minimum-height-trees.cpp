
class Solution {
    /*
    
    Hints to pick choose a node with maximum in nodes
    */
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(!n) return {};
        if(n==1) return {0};
        vector<int> adj[n] ,indegree(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]),
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++,
            indegree[it[1]]++;
        }
        queue<int> q;
        //pushing only those nodes having indegree 1
        for(int i=0;i<n;i++)
            if(indegree[i]==1) 
                q.push(i);
        vector<int> ans;
        while(!q.empty() ){
            ans.clear();
            
            for(int sz=q.size();sz--;){
                int node=q.front();
            q.pop();
                ans.push_back(node);
            //subtracting the indegree of its parnet by 1
            for(int it:adj[node]){
                // indegree[it]--;
                if(--indegree[it]==1) /*if its adj become new leaf node then push it inside queue data structure
                */
                    q.push(it);
                    
                }
            }
            
        }
        return ans;
    }
};
/*
    3 4
*/
