class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /*
        
        1,7,4,9,2,5
        
        
        1,17,5,10,13,15,10,5,16,8
        1 17 5 10 5 16 8
        
        
        when encountering the new guy update cur guy with highest               possible height until now
        
        
        Try some underlying test cases :
        15 12  8 31 13 11 18 4 444  12
        
        
        
         
         
        */
        int n=nums.size();
        int maxLen=0;
        int prev_direction=-9000000; //arbitrary value
        for(int i=1;i<n;i++){
            int direction=nums[i]-nums[i-1];
            direction=(!direction)?0: (direction<0) ? -1 :1 ;
            cout<<direction<<endl;
            if(  !direction || direction==prev_direction ){
                //dont update maxLen  
                continue;
            }
            else{ // found an alternating pair
                //update maxLen
                maxLen++,
                //update prev_direction
                prev_direction=direction;
            }
        }
        // for(int i=1;;)
        return maxLen+1;
    }
};