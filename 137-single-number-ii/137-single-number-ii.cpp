class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0,i,bitSum;
        for( i=0,bitSum=0;i<32;i++,bitSum=0){
            
            for(int n:nums){
                bitSum+=((n>>i) &1) ;
            }
            if(bitSum % 3){
                ans|=(1<<i);
            }
        }
        return ans;
    }
};