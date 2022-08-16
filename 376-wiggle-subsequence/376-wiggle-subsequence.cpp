class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /*
        
        1,17,5,10,13,15,10,5,16,8
        
        */
        
        int n=nums.size(),i=1,cnt=0,prev=nums[0], slopeNature=0;
        if(n<2)
            return n;
        while(i<n){
            if(!slopeNature){
                if(nums[i]>nums[i-1])
                    cnt++,slopeNature=1,prev=nums[i];
                else if(nums[i]<nums[i-1])
                    cnt++,slopeNature=-1,prev=nums[i];
//          
            }
            else if(slopeNature<0){
                if(nums[i]>nums[i-1]){
                    cnt++,slopeNature=1;
                }
            }
//        if last     slopeNature is +ve
            else{
                if(nums[i]<nums[i-1]){
                    cnt++,slopeNature=-1;
                }
            }
            i++;
        }
        return cnt+1;
    }
};