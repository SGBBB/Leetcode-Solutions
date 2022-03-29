struct vertex{
    int dest,wt;
    vertex(int dest,int wt){
        this->dest=dest,
        this->wt=wt;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vertex> adj[n+1];
        int dist[n+1];
        for(int i=0;i<n+1;i++) dist[i]=105;
        dist[k]=0;
        for(auto it:times){
            adj[it[0]].push_back( vertex(it[1],it[2] ) );
        }
        set<pair<int,int>>s;
        s.insert({0,k});
        while(!s.empty() ){
            auto top=*s.begin();
            s.erase(s.begin());
            int dis=top.first,
                node=top.second;
            for(auto it:adj[node]){
                int adjNode=it.dest,
                    wt=it.wt;
                if(dis+wt<dist[adjNode]){
                    dist[adjNode]=dis+wt,
                    s.insert( {dist[adjNode],adjNode} );
                    
                }
                    
            }
        }
        int ans=-1;
        for(int i=1;i<n+1;i++)
            {ans=max(ans,dist[i]); cout<<dist[i]<<" ";}
        return ans==105 ?-1 : ans ;
    }
};