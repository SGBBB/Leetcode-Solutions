class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        set<int> s(nums.begin(), nums.end());
        long long min_sum=( 1LL*k*(k+1) )>>1;
        k++;
        for(int i:s){
            if(i<k) {
                min_sum-=i,min_sum+=k ,k++;
            }
        }
        return min_sum;
    }
};