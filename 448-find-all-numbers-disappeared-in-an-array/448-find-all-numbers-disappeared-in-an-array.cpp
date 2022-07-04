class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        
        
        4,3,2,7, 8,2,3,1
        0 0 -3 -7 0 0 0 0
        */
        
        int n=nums.size();
         
        
        for(int i=0;i<n;i++){
            int pos=abs(nums[i])-1;
            //if the value at pos is already negativ ethen dont do anything
            if(nums[pos]>0){
                nums[ pos ]*=(-1);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                ans.push_back(i+1 );
        }
        return ans;
    }
};