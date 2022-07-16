class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        /*
        2 6 4 8 10 9 15
        
        must start from idx 2
        we must consider extreme left anomaly point and extreme 
        
        0 1 1 1 -1 2 4 5  3 6 7
        
        1,2,3,4
        
        4 ,3, 2 ,1
        
        stack
        2
        
        start=0
        end=n-1 =3
        */
        stack<int> st;
        int len=nums.size();
        int start=len,end=-1;
        if(len<2)
            return 0;
         
        //computing start idx
        for(int i=0;i<len;i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                start=min({start,st.top()});st.pop();
            }
            st.push(i);
        }
        if(start==len)
            return 0;
        while(!st.empty())
            st.pop();
        //computing the extremee right idx
        for(int i=len-1;i>-1;i--){
            while(!st.empty() && nums[i]>nums[st.top()]){
                end=max({st.top(),end});
                st.pop();
            }
            st.push(i);
        }
        return end-start+1;
        /*
        
        
        */
        
    }
};