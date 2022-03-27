bool cmp(vector<int> &a,  vector<int> &b){
    return a[0]!=b[0] && (a[0]<b[0] )   ;
    return a[0]==b[0] && a[1]<b[1] ;
}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(); cout<<"n is "<<n <<endl;
        vector<vector<int>> adj(n,vector<int> (2));
        set<pair<int ,int >> s;// pair's first is  holding cnt ,seconod is holding index
        if(!k) return {};//if k is 0 then consider returnning empty vector
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<mat.front().size();j++){
                cnt+=mat[i][j]==1;
            }
            adj[i][0]=(cnt);
            adj[i][1]=(i);
            s.insert({cnt,i});
        }
        /*
        0th index of every row is holding cnt of soldiers
        1st index of every row is holding index of rows
        */
        // sort(adj.begin(),adj.end(), cmp);
        vector<int> ans;
        // for(vector<int> i:adj){
        //     if(k-- ==0){
        //         break;
        //     }
        //     ans.push_back(i[1]);
        // }
        while(!s.empty() && k--){
            auto top=*s.begin();
            ans.push_back(top.second);
            s.erase(*s.begin());
        }
        return ans;
    }
};