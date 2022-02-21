class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()/2,cnt=0,ans=nums.front();
        for(int i:nums){
            cnt+=(ans==i) ;
            if( cnt> n ) return i;
            if(ans!=i){
                
                cnt=1,ans=i;
            }
                
            
        }
        return -1;
    }
};