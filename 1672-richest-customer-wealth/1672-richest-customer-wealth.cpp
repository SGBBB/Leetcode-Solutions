class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0,m=accounts.size(),n=accounts[0].size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            sum=0;
            for(int j=0;j<n;j++)
            {sum+=accounts[i][j];}
            ans.push_back(sum);            
        }
        vector<int> ::iterator max=max_element(ans.begin(),ans.end());
        return *max;
    }
};