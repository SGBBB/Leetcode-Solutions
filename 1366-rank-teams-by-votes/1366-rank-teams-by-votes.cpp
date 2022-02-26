vector<vector<int> > ans(26,vector<int> (26) );
bool cmp(char x,char y){
    return ans[x-'A']>ans[y-'A'] or (  ans[x-'A']==ans[y-'A']   and  x<y);
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n=votes.size();
        if(n==1) return votes.front();
        // vector<vector<int> > ans(26 );
        for(auto &i:ans)
        fill(i.begin(),i.end(), 0);
        for(auto str:votes){
            int idx=0;
            for(char ch:str){
                ans[ch-'A'][idx++]++;
            }
            
        }
        string res=votes.front();
        sort(res.begin(),res.end(),cmp);
//         
        
        //weave the string
        
        return res;
    }
};
// "WXYZ","XYZW"
//  X