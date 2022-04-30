
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) { 
        int arr[m][n];
        memset(arr,0,sizeof arr);
        queue< vector<int> > q;
        for(auto it:walls)
            arr[it[0]] [it[1]]=-2  ;
        for(auto it:guards)
            q.push( {it[0],it[1]} ), 
            arr[it[0]] [it[1]]=-2  ;
        int sz=q.size();
        // cout<< " initially q.size() is " << sz<<endl;
        while( sz--){
            auto frontGuy=q.front();
            q.pop();
            int i=frontGuy[0],
                j=frontGuy[1];
            int dir[]={-1,0,1,0,-1}; //URDL
            for(int k=0;k<4;k++){
                int s=(!dir[k] ) ? dir[k+1] : dir[k] ;
                if(dir[k]==0 ){ //now i'm travelling horizontally
                        while(true){
                            int x=i,
                            y=j+s; //cout<<"travelling horizontally " << x<< " "<<y <<endl;
                            if(min(x,y) >=0 && x<m &&  y<n &&  (arr[x][y]>-1   ) ) {
                                arr[x][y]++;
                            }
                            else break;
                            s+=dir[k+1];
                        
                    }
                }
                else{ //now dir[k+1] is 0 
                    while(true){ //now i'm travelling vertically
                            int x=i+s,
                            y=j; //cout<<"travelling vertically " << s<<" "<< x<< " "<<y <<endl;
                            if(min(x,y) >=0 && x<m &&  y<n &&  (arr[x][y]>-1 ) ) {
                                arr[x][y]++;
                                   
                            }
                            else break;
                            s+=dir[k];
                    }
                }
                
             
            
            
        }
        }
        //done executing the while loop
        int cnt=0;
        for(auto i=0;i<m;i++){
            for(int j=0;j<n;j++) 
                cnt+=(!arr[i][j]);
        }
        cout<<"printing guys"<<  cnt<<endl; 
        return cnt;
    }
    
};
/*

How will you approach this  problem???
Observations:
1. the cells holding wall is just a blocked cell 
2. we can start running bfs on the guarded cell ,so eventually all guarded cel will enter in queue for sure.


*/