class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int > M;
        for(auto i:nums)
            M[i]++;
        int ans=0;
        for(auto i:nums){
            if(M.find(i-1)!=M.end()) continue;
            else{
                int size=1;
                int curr=i+1;
                while(M.find(curr)!=M.end() ){
                    curr++;
                    size++;
                }
                ans=max(ans,size);
            }
                
        }
        return ans;
    }
};