
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
	void unionSize(int pu, int pv) {
// 		int pu = findPar(u);
// 		int pv = findPar(v);
        pu=findPar(pu),pv=findPar(pv);
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

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(27); //assigning size equivalent to alphabet count
        for(auto it:equations){
            int guy1=it[0]-'a',guy2=it[3]-'a';
            int guy1Par=dsu.findPar(guy1),guy2Par=dsu.findPar(guy2);
            //if both guys are claimed to be equal 
            if(it[1]=='='){
                // if both are possessing different parent
                if(guy1Par!=guy2Par){
                    dsu.unionSize(guy1,guy2);
                    // if()
                }
                    
                
                  
                
                
            }
            
            
        }
        for(auto it:equations){
            int guy1=it[0]-'a',guy2=it[3]-'a';
            int guy1Par=dsu.findPar(guy1),guy2Par=dsu.findPar(guy2);
            //if both guys are not equal 
            if(it[1]=='!'){
                // if both guys are Possessing same parent 
                if(guy1Par==guy2Par)
                    return 0;
            }
        }
        //if everything went well then return true at end
        return 1;
    }
};