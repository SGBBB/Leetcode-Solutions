class Solution {
    void calculate_subsets( vector<int> &nums ,  vector<vector<int> > &res,vector<int> &path ,int idx=0){
        res.push_back(path);
        int n=nums.size();
        int i=idx;
        for(;i<n;i++){
            path.push_back(nums[i]);
            calculate_subsets(nums,res,path,i+1);
            path.pop_back();
        }
        
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        calculate_subsets(nums,res,path);
        return res;
    }
};