class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //LEt me initially store indices corresponding to every value
        unordered_map<int , int  > M;
        int idx=0;
        for(int num:nums){
            if( M.count(num) ){
                if(idx-M[num]<=k) return true;
            }
            M[num]=idx++;
        }
        return false;
    }
};
/*
1 3
2 1
3 2

*/