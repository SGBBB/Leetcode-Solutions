class Solution {
public:
    /*
    5  7   11    11
    
    
    5 3 4 4 7 3 6 11 8 5 11
    
    
    5 3 4 4 7
    
    7 2 1 3 5 1 3 6 11
    
    Emphasis on this statement:
    A guy having no bigger to it's left cant be removed at any step.
    
    I think given test cases are enough to solve the problem:
    eg2:
    11 8 5 11
    Result-->11 11
    */
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        int cnt_arr[n];
        stack<int> st;
        int steps=0;
        memset(cnt_arr,0,sizeof cnt_arr);
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            while( !st.empty() &&   nums[i]>nums[st.top()]  ){
                cnt=max({cnt+1,cnt_arr[st.top()]}),
                st.pop();
            }
            steps=max({steps,cnt});
            
            cnt_arr[i]=cnt,
            st.push(i);
        }
        return steps;
         
    }
};