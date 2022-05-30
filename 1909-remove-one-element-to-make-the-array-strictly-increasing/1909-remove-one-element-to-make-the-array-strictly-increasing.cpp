class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        /*
        Seems like its a stack problem
        breute force approach is to try deleting every  element then check whether the             resultant arr is increasing or not???
        
        Challenge:Try to think some optimal linear time complexity solutoion
        Hint: When we find out of order element, there can be two scenarios : keep i th element or keep i-1 the element.
        
        Try to think some test cases:
        
        1 2 5 16 8  15 23 33 35
        1 2 5 16 8  15 23 33 35
        
        [105,924,924,968]
        */
         
        int n=nums.size(),cnt=0;
        nums.insert(nums.begin()+0,-1002);//pushing mighty element to the last 
        for(int i=1,len=nums.size();i<len;i++){
            // if some dgiit is out of order then 
            if( nums[i]<= nums[i-1] ){
                if(cnt==1) 
                    return false;
                /*
                
                if we met anomaly for the first time
                
                */
                cnt++;
                //We will only keep nums[i] if it satisfies below condition
                if( nums[i ]>nums[i-2]   ){
                    // i would have removed  nums[i]
                    nums[i-1]=nums[i];
                }
                else{
                    nums[i]=nums[i-1];
                }
            }
        }
        // if(cnt>1) return false;
        
        
        /*
        if the array is strictly inreasing then return tru;
        */
        return true;
    }
};