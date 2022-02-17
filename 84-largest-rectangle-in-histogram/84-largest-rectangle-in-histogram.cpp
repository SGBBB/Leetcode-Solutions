class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int i,n=heights.size(),max_area=0;
        for(i=0;i<=n;i++){
            for(;  st.size() and (i==n or heights[i]<heights[st.top()])  ;){
               int curr_height= heights[st.top()] ; 
                st.pop();
               int width ;
               width=(st.empty() ) ? i  : i-st.top()-1 ; 
               max_area=max(max_area, width* curr_height) ;
                
                
            }
            st.push(i);
        }
        
        return max_area;        
        // worst case complexity O(n) + O(n)
    }
};