class DSUu{
    vector<int> parent,componentSize;
    public:
    DSUu(int n){
        for(int i=0;i<=n;i++)
            parent.push_back(i),
            componentSize.push_back(1);
    }
    //This will return the ultimate parent
    int findParent(int node){
        //This is the condition to check ultimate parent
        if(parent[node]==node)
            return node;
        parent[node]=findParent(parent[node]);
        return parent[node];
            
    }
    void unionComponents(int node1,int node2){
        //Finding the ultimate parent corresponding to every node
        int parent1=findParent(node1),
        parent2=findParent(node2);
        // If both the components are same then do nothing
        if(parent1==parent2) return;
        if(componentSize[parent1] < componentSize[parent2]){
            parent[parent1]=parent2,
            componentSize[parent2]+=componentSize[parent1];
            return ;
        }
        parent[parent2]=parent1,
        componentSize[parent1]+=componentSize[parent2];
    }
    
};
struct node{
    int s,e,wt;
    node(int s,int e,int wt){
        this->s=s,
        this->e=e,
        this->wt=wt;
    }
};
class DSU {
	vector<int> parent, size ;
 
public:
    //This DSU supports both 0 and 1 based indexing
	DSU(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			size.push_back(1);
		}
	}
 
 
public:
    //This function will return the ultimate or superparent of the component
	int findParent(int node) {
	    //checking if node is itself the superparent or not??????
		if (parent[node] == node) {
			return node;
		}
		// path compression -> (log n)
		// path compression and size -> O(4 x alpha)
		return parent[node] = findParent(parent[node]);
	}
 
public:
	void unionComponents(int u, int v) {
		int pu = findParent(u);
		int pv = findParent(v);
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
bool comp(node first,node second){
    if(first.wt<second.wt) return true;
    return false;
}
//The question states that you are given n coordinates
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU dsu(n);
        
        vector< node > edges;//wt, int x, int y
        multiset< vector<int> > store;
        for(auto i=0;i<n-1;i++)
            for(auto j=i+1;j<n;j++){
            int dist=abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vector<int> temp={dist,i,j};
                edges.push_back(node(i,j,dist));
                // store.insert(temp);
            }
        
        sort(edges.begin(),edges.end(),comp);
        int cost=0;
//         for(; !store.empty() ; store.erase( *store.begin() ) ){
//             auto it=*store.begin();
//             int s=it[1],e=it[2];
//             int parent_s=dsu.findParent(s),parent_e=dsu.findParent(e);
//             //if both the componenets are different then do union
//             if(parent_s!=parent_e) {
//                 dsu.unionComponents(s,e),
//                 cost+=it[0];
//             }
            
//         }
        for(auto it:edges){ 
            int s=it.s,e=it.e, wt=it.wt;
            int parent_s=dsu.findParent(s),parent_e=dsu.findParent(e);
            //if both the componenets are different then do union
            if(parent_s!=parent_e) {
                dsu.unionComponents(s,e),
                cost+=wt;
            }
        }
        return cost;
        
    }
};