class Solution {
    /*
    
    You can see the right next greater element.
Your left next greater element can see you.


10 6 8 5 11                         9
              1                         0
    To solve this problem in quadratic time complexity, for every guy we will move until its very near bigger guy, because i'll not be able to see after my nearest bigger guy.


    10 6 8 5 11 
    
     0 2 3  
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
