vector<int> t,bhenchod;

/*
9
2
[2,2,-1,2,2,2,1,5,5]
[0,2,1,0,0,6,0,0,0]


*/
class Solution {
    int dfs(int node,vector<int> adj[100001]){
        int res=0;
        for(auto it:adj[node]){
            res=max(res,dfs(it,adj));
            // if(it==1 or it==5)cout<<res<<" "<<endl;
        }
        return res+t[node];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[100001];
        t=informTime;
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                // if(i==6 ) cout<<"i is 6 now "<< manager[i]<<i<<endl;
                adj[manager[i]].push_back(i);
            }
        }
        // int idx=0;
        // for(auto i:adj){cout<<idx++<<" ";
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        return dfs(headID,adj);
        // return 9;
    }
};