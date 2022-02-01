class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1,len=nums.size();
        if( !len )return {first,last};
        //find the first occurance
        int l=0,h=len-1;
        while(l<=h){
            int mid=((h+l)/2);
            if(nums[mid]>=target){
                if(nums[mid]==target)first=mid;
                h=mid-1;
            }
            else l=mid+1;  
        }
        //find last occurance
        
        for(l=0,h=len-1;l<=h;){
            int mid=((h+l)/2);
            if(nums[mid]<=target){
                if(nums[mid]==target) last=mid;
                l=mid+1;//go right
                
            }
                
                
            else h=mid-1;//go left
        }
        
        return {first,last};
        
    }
    /*
    
    
    
    
    */
    
    
    
    
    
};