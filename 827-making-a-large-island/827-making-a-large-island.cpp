class DSU{
    public:
    vector<int> parent,size;
    int findParent(int node){
        //if the current node is ultimate parent then return itself
        if(parent[node]==node) 
            return node;
        //assining every node of a component with it's ultimate parent
        parent[node]=findParent(parent[node]);
        return parent[node]; 
    }
    void unionSize(int node1,int node2){
        //finding the ultimate parent of both the component's
        node1=findParent(node1),
        node2=findParent(node2);
        //if both node's belong to same component
        if(node1==node2)
            return;
        if(size[node1]<size[node2]){
            parent[node1]=parent[node2],
            size[node2]+=size[node1];
        }
        else{ //size[node1]>=size[node2]
            parent[node2]=parent[node1],
            size[node1]+=size[node2];
        }
            
    }
    
    //This is both 0 nas well as 1 based DSU
    DSU(int n){
        for(int i=0;i<=n;i++)
            parent.push_back(i),size.push_back(1);
    }
    
};
class Solution {
//     void dfs(int i,int j,int r,int c){
        
//     }
    /*
    How will you make progress in this problem????
    1 0 1
    0 1 1
    
    
    1 1 1
    1 1 1
    
    1 0
    0 1
    Step 1: join the components which are able to join prelimnary 
    Step 2:
    */
public:
    int largestIsland(vector<vector<int>>& grid) {
        int dir_x[]={-1,+1, 0, 0},
            dir_y[]={0 , 0,+1,-1};
        int r=grid.size() ;
        DSU dsu(r*r+1);
        int max_size=0;
        for(auto i=0;i<r; i++){
            for(int j=0;j<r;j++){
                //if current cell is 0 then do nothing
                if(!grid[i][j]) continue;
                int idx1=i*r+ j+1;
                for(int k=0;k<4;k++){
                    int newX=i+dir_x[k],
                        newY=j+dir_y[k];
                    int idx2=newX*r+ newY+1;
                    if( min(newX, newY)>=0 && max(newX,newY)<r  &&  grid[newX][newY]==1 ){
                        dsu.unionSize(  idx1, idx2);
                    }
                }
            }
        }
        
        //find  maximum size among all component.
        for(int num:dsu.size)
            max_size=max(max_size,num);
        
        for(auto i=0 ;i<r; i++){
            for(int j=0;j<r;j++){
                //if current cell is having 1 then do nothing becoz i only wanna iterate in cells having 0
                if(grid[i][j] ) continue;
                unordered_set<int> S;
                int curr_sz=1;
                int idx1=i*r+ j+1;
                for(int k=0;k<4;k++){
                    int newX=i+dir_x[k],
                        newY=j+dir_y[k];
                    int idx2=newX*r+ newY+1;
                    if( min(newX, newY)>=0 && max(newX,newY)<r &&  grid[newX][newY]==1 ){
                        int node=dsu.findParent( dsu.parent[idx2]);S.insert(node);
                    }
                        
                }
                
                for(auto it:S)
                    curr_sz+=dsu.size[it];
                max_size=max(max_size,curr_sz);
                    
            }
        }
        
        return max_size;
    }
};