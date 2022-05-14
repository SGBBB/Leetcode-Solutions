class Solution {
public:
    /*
    How will i approach this problem???
    I already sensed it as a bfs probelm
    One naive approach comes to my brain to try with every single coordinate 
    this will take O( (m*n)^2 ).
    
    
    Problem statement is bit tricky to understand at the first sight 
    eg. if you consider cell[3][3] then it   cant reach top ocean (paciific ocean ) becoz above it there is 3 and above 3 there is 4 which will not let 3 heights[2][3] to reach top 
    therefore heights[3][3] will not reach top.
    
    consider two traversals 
         3,0  4,0 
       1,1  1,2  1,3 2,1 
    
    */
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size(),c=heights[0].size();
        vector<vector<int>> ans;
        bool pacific_points[r][c],atlantic_points[r][c];
        memset(pacific_points,0,sizeof pacific_points);
        memset(atlantic_points,0,sizeof atlantic_points);
        queue<vector<int>> pacific_q,atlantic_q;
        for(int i=0;i<r;i++)
                pacific_q.push({i,0}),pacific_points[i][0]=1,
                atlantic_q.push({i,c-1}),atlantic_points[i][c-1]=1;
        
        for(int i=0;i<c;i++)
                pacific_q.push({0,i}),pacific_points[0][i]=1,
                atlantic_q.push({r-1,i}),atlantic_points[r-1][i]=1;
        
        int dir[]={-1,0,1,0,-1};
        while(!pacific_q.empty()){
            vector<int> top=pacific_q.front(); pacific_q.pop();
            int i=top[0],
            j=top[1];
            // cout<< i<<" "<<j<<" "<< pacific_points[i][j]<<endl;
            for(int k=0;k<4;k++){
                int newi=i+dir[k],newj=j+dir[k+1];
                if(min(newi,newj)>=0 && newi<r && newj<c && !pacific_points[newi][newj] && 
                  heights[newi][newj]>=heights[i][j]
                  )
                    pacific_q.push({newi,newj}), pacific_points[newi][newj]=1;
            }
        }
        //travelling atlantic_q
        while(!atlantic_q.empty()){
            vector<int> top=atlantic_q.front(); atlantic_q.pop();
            int i=top[0],
            j=top[1];
            
            for(int k=0;k<4;k++){
                int newi=i+dir[k],newj=j+dir[k+1];
                if(min(newi,newj)>=0 && newi<r && newj<c && !atlantic_points[newi][newj] && 
                  heights[newi][newj]>=heights[i][j]
                  )
                    atlantic_q.push({newi,newj}), atlantic_points[newi][newj]=1;
            }
        }
        // for(int i=0;i<r;i++)
        //     for(int j=0;j<c;j++)
        //         cout<< pacific_points[i][j]<<" == "<<atlantic_points[i][j]<<endl;
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            //The required coordinate must be available in both boolean matrices
            if( min(pacific_points[i][j], atlantic_points[i][j])==1  ) 
                ans.push_back({i,j});
        return  ans; 
        
    }
};