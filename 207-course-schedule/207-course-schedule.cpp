
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int> > adj(100001);
        int indegree[100001]={};
        for(auto i:prerequisites){
            indegree[i[0]] ++;
            adj[i[1]].push_back(i[0]);
        } 
        for(int i=0;i<numCourses;i++){
            if(!indegree[i])
                q.push(i);
            
        }
        int cnt=0;
        vector<int> ans;
        for(;q.size();){
            auto top=q.front(); q.pop();
            cnt++;
            
            for(int it:adj[top]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
                
            }
                
                    
        }
        return cnt==numCourses;
    }
};