class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        /*
        4 2 3
        
        2 2 3
        
        
        4 2 1
        4 2 3
        
        [ -4 ,1 ,0 ,   2, 3,2 ]
        
        [0 ,   3 , 2 , 3 ]
        [3,5,1,17,23]
        Something is fishy in this problem, this cant be that easy as it looks 
        deceptive problem
        */
        int cnt_anomalies=0,sz=nums.size();
        
        for(int i=1;i<sz;i++){
            if( nums[i-1] > nums[i] ){
                // already met anomaly once so have to return false now
                if( cnt_anomalies )
                    return false;
                if(i>=2 && nums[i-2]>nums[i])
                    nums[i ]=nums[i-1]; //increasing value
                else 
                    nums[i-1]=nums[i];  // decreasing value
                cnt_anomalies++;
            }
        }
        
        return true;
    }
};