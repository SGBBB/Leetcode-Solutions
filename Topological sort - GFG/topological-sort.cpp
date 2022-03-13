// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
	public:
	int visited[1000001];
	vector<int> ans;
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adjacent[]) 
	{
	    stack<int> st;
	    for(int i=0;i<V;i++) visited[i]=0;
	    ans.clear(); 
	    for(int i=0;i<V;i++)
	        if(!visited[i])
	            toposortHelper(adjacent,i,st);
	   for(;st.size();st.pop() ){
	       ans.push_back(st.top() );
	   }
	   return ans;
	        
	}
	void toposortHelper( vector<int> adj [],int node,stack<int> & st){
        visited[node]=1;
        for(int i:adj[node])
            if(!visited[i]) 
                toposortHelper(adj,i,st);
        
        st.push(node);
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends