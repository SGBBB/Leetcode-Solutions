struct Node{
    Node* arr[26];
    bool flag=false;
};
Node * root=new Node();

class Solution {
    void insert(string word){
        Node* temp=root;
        for(char ch:word){
            int idx=ch-'a';
            if(!temp->arr[idx]) temp->arr[idx]=new Node();
            temp=temp->arr[idx];
        }
        temp->flag=true;
    }
    
    void dfs(vector<vector<char>>& board ,int i,int j,set<string> & res ,Node* temp,string path=""){
        int m=board.size(),n=board[0].size();
        if(i<0 or i>m-1 or j<0 or j>n-1 or board[i][j]==' ' ) return;
        if(temp->arr[board[i][j]-'a']  ){
            
            char ch=board[i][j];//cout<<" printing letter "<<(temp->arr[board[i][j]-'a']  )<<ch<<"   "<<temp->flag<<endl;
            path+=ch;
            temp=temp->arr[ch-'a'];
            if(temp->flag ) { res.insert(path);}
            board[i][j]=' ';
            dfs(board,i-1,j,res,temp,path);
            dfs(board,i+1,j,res,temp,path);
            dfs(board,i,j-1,res,temp,path);
            dfs(board,i,j+1,res,temp,path);
            board[i][j]=ch;
            
        }
        
        
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new Node();
        
        int m=board.size(),n=board[0].size();
        for(string str:words) insert(str);
        set<string> res;
        for(int i=0,j=0;i<m;i++){
            for(j=0;j<n;j++){
                Node* temp=root;
                dfs(board,i,j,res,temp);
            }
        }
        vector<string>ans(res.begin(),res.end());
        return ans;
    }
};