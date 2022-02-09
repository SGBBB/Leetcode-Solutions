class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        for(int i:nums) M[i]++;
        int cnt=0;
        for(auto [key,value]:M){
            if( ( !k and M[key]>1 ) or (k>0 and M.count(key-k) )  ) cnt++;
            
        }
        return cnt;
    }
};