class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1=0,xor2, n=nums.size();
        for(int n:nums ) xor1^=n;
        int set_bit;
        for(int i=0;i<32;i++){
            
            if( xor1 & ( 1<<i )  ) 
            {
                set_bit=i;
                break;
            }
        }
        vector<int> ans(2);
        for(int n:nums){
            if( n & (1<<set_bit) )  //syntax of bitwise left shift is number<<bits to be shifted
                ans[1]^=n;
            else ans[0]^=n;
        }
        return ans;
        
    }
};