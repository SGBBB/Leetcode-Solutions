class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int Left_score=0,Right_score=0,len=nums.size();
        vector<int> ans;
        for(int i=0;i<len;i++){
            Right_score+=nums[i];
        }
        int max_score=INT_MIN;
        unordered_map<int,vector<int> > M;
        M[Right_score].push_back(0);
        max_score=max(max_score,Right_score);
        for(int i=0;i<len;i++){
            Left_score+=!nums[i];
            Right_score-=nums[i];
            M[Left_score+Right_score].push_back(i+1);
            max_score=max(max_score,Left_score+Right_score);
        }
        
        return M[max_score];
    }
};