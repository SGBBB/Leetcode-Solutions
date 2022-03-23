class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        // set<int> poppedElements(popped.begin(),popped.end());
        int i=0;
        for(int val:pushed) {
            st.push(val);
            while( st.size()  and st.top()==popped[i]) {
                st.pop(); i++;
            }
        }
        
        return st.empty();
    }
};