class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         long long mod = (1e9 + 7); 
         long long dist[n],ways[n];
         dist[0]=0;
         ways[0]=1;
        for(int i=1;i<n;i++) ways[i]=0,dist[i]=LLONG_MAX;
        
        //filling our adj list
        vector<pair<long ,long>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        set< pair<long long ,long long > > s;
        s.insert({0,0});
        while(!s.empty() ){
            auto cur=*s.begin();
            s.erase(s.begin());
            long long dis=cur.first,
            node=cur.second;
            for(auto it:adj[node]){
                long long wt=it.second,
                     adjNode=it.first;
                
                if(dis+wt<dist[adjNode]  ) {
                    dist[adjNode]=dis+wt;
                    ways[adjNode]=ways[node];
                    s.insert({dist[adjNode],adjNode});
                }
                else if(dis+wt==dist[adjNode] ) 
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }
            
            
        }
        return ways[n-1];
    }
};