class Solution {
    void dfs(vector<vector<int>> & graph,vector<vector<int>> &res,
             vector<int> path,int node=0){
      int n=graph.size();
      if(node==n-1){
          
          res.push_back(path);
          
          return ;
      }
      for(int i:graph[node]){
          path.push_back(i);
          dfs(graph, res, path,i);
          path.pop_back();
      }  
       
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        dfs(graph,res,{0});
        return res;
    }
};