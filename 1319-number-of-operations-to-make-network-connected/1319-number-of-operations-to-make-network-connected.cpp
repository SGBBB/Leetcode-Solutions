class DSU{
    
    int sz;
    vector<int> componentParent,componentSize;
    public:
    DSU(int sz){ //This DSU is both 0. as well as 1 base DSU
        this->sz=sz;
        for(int i=0;i<=sz;i++){
            componentParent.push_back(i),
            componentSize.push_back(1);
        }
        
    }
    
    int findParent(int node){
        // if current node is the ultimate parent of the component then return it
        if(componentParent[node]==node)
            return node;
        return componentParent[node]=findParent(componentParent[node]); 
    }
    
    void unionComponents(int node1,int node2){
        int  node1Parent=findParent(node1),
             node2Parent=findParent(node2);
        if(node1Parent==node2Parent)
            return ;
        
        if(componentSize[node1Parent]<componentSize[node2Parent]){
            componentSize[node2Parent]+=componentSize[node1Parent],
            componentParent[node1Parent]=componentParent[node2Parent];
            
        }
        else
            componentSize[node1Parent]+=componentSize[node2Parent],
            componentParent[node2Parent]=componentParent[node1Parent];
        
        
    }
};
class Solution {
public:
    /*
        Are the given connections / edges sufficient to make all compmppnenets connected??
        How will I check this
        There must be atleast n-1 onnections / edges 
        
        Now, lets assume that we have enogh connections to connect all devices
        Find the number of disconnected components?
        n-(total number of components participating in connnections)
        
        I have constructed my algorith  ,
        Try to test some miscellaneoous test cases against my algo.
        
        Task: I believe that the givenn problem boils down to asking we wanna find the count of redundant connections 
        
    */
    int makeConnected(int n, vector<vector<int>>& connections) {
        int originaln=n;
        int len=connections.size();
        // if count of connection     is insufficient
        if(len<n-1)
            return -1;
        
        //Now Im having enough connections to connect each computer into 1.
        DSU dsu(n);
        int redundantConnections=0;
        set<int> connectedComponents;
        for(auto it:connections){
            int component1=it[0],
                component2=it[1];
            connectedComponents.insert(it[0]);
            connectedComponents.insert(it[1]);
            if(dsu.findParent(component1) !=  dsu.findParent(component2)){
                //call unionComponents method
                dsu.unionComponents(component1,component2),n--;
            }
            else{
                redundantConnections++;
            }
        }
        cout<<"len is "<<len<<" "<<redundantConnections<<" "<<connectedComponents.size() <<endl;
        cout<<" my ans " <<min(redundantConnections,(int)(originaln-connectedComponents.size() +1));
        return n-1;
    }
};