vector<int> adj[100002];
int dist[100002];
int maxi=1 ;
class Solution {
    void dfs(  string &s,int node ){
        dist[node]=1;
        for(auto it:adj[node]){
            
            dfs(s,it ); 
            if( s[node]!=s[it] ){
                //Now i can include node guy becoz chars are not equal
                maxi=max(maxi,dist[node]+dist[it]);
                dist[node]=max(dist[node],dist[it]+1);
            }
        }
    }
public:
    int longestPath(vector<int>& parent, string s) {  
        memset(dist,1, sizeof dist);
         maxi=1;//becoz at worst case if all nodes have equal char then ans will be 1  
        for(int i=1,n=parent.size();i<n;i++){
            adj[parent[i] ].push_back(i);
        }
        // cout<<"maxi above "<<adj.size()<<endl; 
        dfs( s,0 );
        // cout<<"maxi below "<<adj.size()<<endl; 
        // vector<int> copy[100002];
        for (auto& v : adj) {
            v.clear();
        }
        // adj=copy;
        return maxi;
        
        
        
    }
};


/*
 0 1 2 3 4 5 <-nodes
-1,0,0,1,1,2
 a b a c b e
 
Is this actually tree problem do we really required to consstruct a tree tp splve this?????
Use given data to create an undirected graph.

I cant even wonder solving this problem using recursioin becoz constraints are really huge!

NOTE:While considering a path do consider root guys as a part if path as well.

Why are you obsessed with writing code 
Why dont you initilly think about logic?????

*/