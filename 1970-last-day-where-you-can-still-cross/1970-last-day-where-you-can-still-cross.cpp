int dir[]={-1,0,1,0,-1};
class Solution {
    vector<vector<int>> grid;
public:
    /*
    points to ponder:
    try to collect observation from the context of the problem
    Try to build intuition 
    intuition: use binary searhc in ans
    i am able to decifer a lot of problem.
    5 1 6
    2 4 7
    9 8 3
    
    0    1(Y)   2()        3     4(No)   9    
    
    NotE: at ith day, intialy the cell is flooded then man is walking 
    */
    bool bfs(int mid){
        int r=grid.size(), c=grid[0].size();
        bool vis[r][c];
        memset(vis,0,sizeof vis);
        queue<vector<int>> q;
        for(int i=0,sz=grid[0].size();i<sz;i++){
            int it=grid[0][i];
            if(it<=mid)
                continue;
            q.push({0,i,mid,0}),vis[0][i]=1;
            
        }
        
        while(!q.empty()){
            int i=q.front()[0],
                j=q.front()[1],
            steps=q.front()[2],
            row_cnt=q.front()[3];
            q.pop();
            if(row_cnt==r-1) //if im able to reach the last row then consider returning true;
                return true;
            // if(grid[i][j]<=steps)
            for(int k=0;k<4;k++){
                int newi=i+dir[k],
                    newj=j+dir[k+1];
                if( min(newi,newj)<0 || newi>=r || newj>=c || vis[newi][newj] ||
                   grid[newi][newj]<=steps)
                    continue;
                q.push( { newi,newj,steps,row_cnt+newi-i } ),vis[newi][newj]=1;
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        grid.resize(row, vector<int>(col));
        int l=0 ,h=cells.size(),best=cells.size();
        
        int idx=1;
        for(auto it:cells)
            grid[it[0]-1][it[1]-1]=idx++;
        
        // for(auto arr:grid){
        //     for(auto it:arr)
        //         cout<<it<<" ";cout<<endl;
        // }
        while(l<=h){
            int mid=l+(h-l)/2;
            bool isTrue=bfs(mid);
            cout<<mid<<" "<< isTrue <<endl;
            if(isTrue)
                best=mid,l=mid+1;
            else
                h=mid-1;
        }
        return best ;
    }
};

