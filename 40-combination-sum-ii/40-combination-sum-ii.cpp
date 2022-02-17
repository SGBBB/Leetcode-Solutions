class Solution {
    vector<vector<int>> ans;
    void helper(vector<int>& candidates, int target,  vector<vector<int>> &ans,
                vector<int> &temp ,int start=0,int level=0){
        
        if(target>-1 ) {
            cout<<"level is "<<level<<endl;
            if(!target) {  ans.push_back(temp);     return ;}
            int idx,n=candidates.size();
            for(idx=start;idx<n;idx++){
                if(candidates[idx]>target) continue;
                if(idx == start || candidates[idx] != candidates[idx-1]){
                    temp.push_back(candidates[idx]);
                    helper(candidates,target-                                                 candidates[idx],ans,temp,idx+1,level+1);
                    temp.pop_back();
                }
                
            }
            
        }
        // if my target is <=-1 so i dont need this anymore lets backtrack from this positiioon as its dead end
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(candidates , target,ans,temp);
        return  ans;
    }
};