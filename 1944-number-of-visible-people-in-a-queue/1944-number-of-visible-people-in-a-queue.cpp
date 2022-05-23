class Solution {
    /*
    Do heavy emphasis on this phrase: Ans will be submitted
    You can see the right next greater element.
Your left next greater element can see you.


10 6 8 5 11                         9
              1                         0
    To solve this problem in quadratic time complexity, for every guy we will move until its very near bigger guy, because i'll not be able to see after my nearest bigger guy.


    10 6 8 5 11 
    
     0 2 3  
     
     Try to think for smaller test cases
     like below:
     [10, 6]
     above array is already monotonically decreasing you if you dont do some extra effort then ans for 10  will not be incremented by 1.
     
     Scene : You are at 6 and you already have 10 inserted in your stack 
     As the stack is monotonically decreasing
     try to think can you see 6 from last greater height? if yes then 
     do ans[st.top()]++
*/
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // 
        vector<int> ans(heights.size());
        stack<int> st;
        for(int i=0,n=heights.size();i<n;i++){
            while(!st.empty() && heights[st.top()]<heights[i]) {
                ans[st.top()]++;
                st.pop();
            }
            if(!st.empty())
                ans[st.top()]++;
            st.push(i);
        }
        return ans;
    }
};
