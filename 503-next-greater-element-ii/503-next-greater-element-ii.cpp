class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { 
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,INT_MIN);
        for(int i=0;i<2*n-1;i++){
            int pos=i%n;
            while(!st.empty() && nums[st.top()]<nums[pos] ){
                ans[st.top()]=nums[pos],
                st.pop();
            }
            
            
            st.push(pos);
            
        }
        while(!st.empty()){
            if(ans[st.top()]==INT_MIN)
                ans[st.top() ]=-1;
            st.pop();
        }
        return ans;
    }
};
/*
    1 2 3 4 3 1 2 3 4 3
    
    1 2 1 
    
    
    
    another test case:
    4 1 2 1 
   -1 2 4 4  
*/