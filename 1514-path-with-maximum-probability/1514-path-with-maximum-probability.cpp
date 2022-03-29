struct vertex{
    int dest;
    double wt;
    vertex(int dest,double  wt){
        this->dest=dest,
        this->wt=wt;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vertex> adj[n];
        vector<double> dist(n,0.00000);
        dist[start]=(double)1.0;
        for(int i=0,sz=edges.size();i<sz;i++){
            
            auto it=edges[i];
            auto wt=succProb[i];
            adj[it[0]].push_back(vertex(it[1],wt));
            adj[it[1]].push_back(vertex(it[0],wt));
        }
        priority_queue< pair<double,int> > pq;
        pq.push({1.0,start});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            double dis=top.first;
            int node=top.second;
            for(auto it:adj[node]){
                double wt=  it.wt;
                int adjNode=it.dest;
                
                if(dis*wt>dist[adjNode]){
                    dist[adjNode]=dis*wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
            
            
        }
        return dist[end];
        return 0.00000;
    }
};