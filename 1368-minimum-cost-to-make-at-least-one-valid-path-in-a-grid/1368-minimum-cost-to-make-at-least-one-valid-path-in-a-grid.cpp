int dir[]={-1,0,1,0,-1};
string arrow="4132";
class Solution {
    /*
    
    1 1 3
    3 2 2
    1 1 4
    
    I believe all testcases are trivial or enouugh  to solve problem
    */
public:
    int minCost(vector<vector<int>>& grid) {
        // multiset<vector<int>> S;
        using ti = vector<int >;
        priority_queue<ti, vector<ti>, greater<>> S;
        int r=grid.size(),c=grid[0].size();
        int vis[r][c];
        memset(vis,0,sizeof vis);
        S.push({0,0,0});//{cost,i,j}
        while(!S.empty()){
            // vector<int> arr=*S.begin();
            vector<int> arr=S.top();
            int cost=arr[0],
                i=arr[1],
                j=arr[2];
            // auto it=S.lower_bound(arr);
            // S.erase(it);
            S.pop();
            if(vis[i][j])
                continue;
            vis[i][j]=1;
            if(i==r-1 && j==c-1)
                return cost;
            //finding the pos of char in string
            int pos=arrow.find(grid[i][j]+'0');//cout<< "pos == " << pos<<endl;
            //explore all the 4 directions
            
            for(int k=0;k<4;k++){
                int newi=i+dir[k],newj=j+dir[k+1];
                
                if(min(newi,newj)<0 || newi>=r || newj>= c || vis[newi][newj] )
                    continue;
                
                //if im moving in same direction as arrow in cur cell then 0 cost will be added
                if(k==pos){
                    S.push({cost,newi,newj});
                }
                else{ //1 will be added if im moving in other 3 directions
                    S.push({cost+1,newi,newj});
                }
            }
            
        }
        return 0;
    }
    /*
    1R
    2L
    3D
    4U
    
    You may or may not change the dir its completely optional
    try to minimize the cost at every cell
    
    1 1 3
    3 2 2
    1 1 4
    
    
    1 2 
    4 3
    
    [[1,2],[4,3]]
    
    intuitioin : if you are going in  deirction samke as arrow then 0 cost will be added ,else in moving to other 3 directions 1 cost will be added
    */
};