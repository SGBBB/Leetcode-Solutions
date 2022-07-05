class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*
        
    2,(6,4,8,10,9),15  
    
    Observations:
    At worst c ase I will have to consider whole length
    
    1,2,3,4
        
    if previous guy is greater than current guy then anomaly started
    Hence, previous guy is gonna participate in our short-subarray.
    
    
    Do I need to just find the start and end points
    1 4 2 13 9 25   
        
    2 6 4   
        */
        
        int n=nums.size(),maxNumUntilNow=INT_MIN ;
        int startIdx=n,endIdx=-1,visitOnce=0;
        
        /*
        
        Anyway my iteration has to be linear anyhow 
        Taks is to find the last anomalous point
        
        */
        
        stack<int> st;// stack is holding indices
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                //I wanna choose extremely smaller left anomaly index
                startIdx=min({startIdx,st.top()}),
                st.pop();
            }
            st.push(i);
        }
        
        
        //if startIdx isnt changed then Im sure that array is arranged in ascending order
        if(startIdx==n)
            return 0;
        // Making stack empty for next iteration
        while(!st.empty())
            st.pop();
       for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>nums[st.top()]){
                //I wanna choose extreme right index where anomaly occured
                endIdx=max({endIdx,st.top()});
                st.pop();
            }
           st.push(i);
       }
        
       return endIdx-startIdx+1;
        
        
    }
};