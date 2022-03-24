struct node{
    int i,j;
    node(int i,int j){
        this->i=i,
        this->j=j;
    }
};
int DIR[]={-1,0,1,0,-1}; //this DIR arr follows this dir:URDL
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size() , c=mat[0].size();
        queue<node >q; 
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(!mat[i][j]) //cout<<endl;
                    q.push (  node(i,j) );
                else mat[i][j]=-1;//marking it unprocessed
        while(!q.empty() ){
            int i=q.front().i,
                j=q.front().j;
            cout<<i<<j<<endl;
            q.pop();
            /*Lets explore all 4 directions */
            for(int s=0;s<4;s++){
                int new_i=i+DIR[s] ,new_j=j+DIR[s+1];
                
                if( new_i<r  && new_j<c && new_i>-1 && new_j>-1 && mat[new_i][new_j]==-1 )
                    {cout<<"new idx "<<new_i<<" "<<new_j<<endl;
                     q.push(node(new_i,new_j) ), mat[new_i][new_j]=mat[i][j]+1 ;
                    }
            }
        } 
        return mat;
    }
};