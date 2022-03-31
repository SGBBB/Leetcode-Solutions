class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        for(int i:nums) M[i]++;
        int cnt=0;
        for(auto [key,value]:M){
            /*
            bc 2 cases bnre h 
            1.  ( !k and M[key]>1 ) this means if k is 0 then M[key ] i mean frequency of key must be greater than 1 becoz key-key==0
            2. if k > 0  ,then find whether key -k exists or not?????
            
            */
            if( ( !k and M[key]>1 ) or (k>0 and M.count(key-k) )  ) cnt++;
            
        }
        return cnt;
    }
};