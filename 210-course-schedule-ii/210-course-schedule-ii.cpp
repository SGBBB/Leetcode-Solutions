class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int > adj[100001];
        int indegree[100001]={};
        for(auto i:prerequisites){
            indegree[i[0]] ++;
            adj[i[1]].push_back(i[0]);
        } 
        for(int i=0;i<numCourses;i++){
            if(!indegree[i])
                q.push(i);
            cout<<  " indegree is  "  <<i   <<indegree[i] << endl;
        }
        int cnt=0; //maintaiing a cnt to chck cycles in   graph
        vector<int> ans;
        for(;q.size();){
            auto top=q.front(); q.pop();
            cnt++;
            ans.push_back(top);
            for(int it:adj[top]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
                
            }
                
                    
        }
        if(cnt==numCourses) return ans;
        return {};
    }
};