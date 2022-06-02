class Solution {
    
    /*
    
    Ituition:
    at every cell I'll move to smalal value adjacent cells
    */
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N=grid.size(),
            maxTime=0;
        set<vector<int>> q;//{cur_cell_value,cur_row,cur_col }
        
        vector<vector<int>> seen(N, vector<int>(N, 0));
        vector<int> dir({-1, 0, 1, 0, -1});//URDL
        q.insert( {grid[0][0],0,0} );
        while( !q.empty() ){
            vector<int> frontArr=*q.begin();
            int cur_cell_value=frontArr[0],
                i=frontArr[1],
                j=frontArr[2];
            q.erase(q.begin());
            maxTime=max(maxTime,cur_cell_value);
            //if I have reached at the end then return maximum time value seen until now 
            if(i==N-1 && j==N-1)
                return maxTime;
            for(int k=0;k<4;k++){
                int newi=i+dir[k],
                    newj=j+dir[k+1];
                if( min({newi,newj})<0 || max(newi,newj)>N-1 ||  seen[newi][newj]  )
                    continue;
                q.insert( {grid[newi][newj],newi,newj} ),
                seen[newi][newj]=1;
            }
                
        }
        return -1;
    }
};