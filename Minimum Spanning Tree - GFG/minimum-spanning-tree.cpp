// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class DSU {
	vector<int> parent, size, rank;
 
public:
	DSU(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);
		}
	}
 
 
public:
    //This function will return the ultimate or superparent of the component
	int findPar(int node) {
	    //checking if node is itself the superparent or not??????
		if (parent[node] == node) {
			return node;
		}
		// path compression -> (log n)
		// path compression and size -> O(4 x alpha)
		return parent[node] = findPar(parent[node]);
	}
 
public:
	void unionSize(int u, int v) {
		int pu = findPar(u);
		int pv = findPar(v);
		if (pu == pv) {
			return;
		}
 
		// pu chota
		// pu ko zod pv me
		// pv bolega me bada hogaya re baba, mera size badha de
		if (size[pu] < size[pv]) {
			parent[pu] = pv;
			size[pv] += size[pu];
		}
		else {
			parent[pv] = pu;
			size[pu] += size[pv];
		}
	}

	
};
struct node{
    int u,v,wt;
    node(int u,int v,int wt){
    this->u=u    ,
    this->v=v    ,
    this->wt=wt  ;
    }
};
bool comp(node first,node second){
    if(first.wt<second.wt) return true;
    return false;
}
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // vector<int> neighbourer[V];
        vector<node> edges;
        DSU dsu(V);
        for(int i = 0; i < V; i++){
            for(auto vec: adj[i]){
                edges.push_back(node(i, vec[0], vec[1]));
            }
        }
        sort(edges.begin(), edges.end(), comp);
        int cost=0;
        for(auto it:edges) {
            int u=it.u,
            v=it.v,
            wt=it.wt;
            //If two joining components doesnt belong to same component that means cycle wil not formed
            if( dsu.findPar(u)!=dsu.findPar(v) ){
                dsu.unionSize(u,v);
                cost+=wt;
            }
            
        }
        return cost;   
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends