class Solution {
    map<int ,unordered_set<string> > M;
    void dfs(string &s ,int idx=0 ,  int open=0, int close=0,string temp=""   ) {
        if(close>open) return;
        if(idx==s.size() ) {
            if( open==close  ){
                M[temp.size() ].insert(temp);
            }
            return;
        }
        if( isalpha(s[idx]) )temp+=s[idx];
        // temp+=(   ) ? s[idx]:'' ;
        dfs(s,idx+1,open,close,temp);
        if(s[idx]=='(') {   dfs(s,idx+1,open+1,close,temp+'(');       }
        if(s[idx]==')') {   dfs(s,idx+1,open,close+1,temp+')');       }

    }
public:
    vector<string> removeInvalidParentheses(string s) {
        dfs(s);
        // for(auto i:M){
        //     // cout<<i.first<<" ";
        //     for(auto j:M[3]second )  cout<<j<<" ";
        //     cout<<endl;
        // // }
        // return {"(a)"};
        
        return vector<string> ( M.rbegin()->second.begin()  , M.rend()->second.end() ) ;
    }
};