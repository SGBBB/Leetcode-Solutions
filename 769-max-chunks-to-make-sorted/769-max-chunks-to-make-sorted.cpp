class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int newElement=arr[i];
            int maxi=newElement;            
                while(!st.empty()  and newElement<st.top() ){
                maxi=max(maxi,st.top());
                st.pop();
                }                       
           st.push(maxi); //push maxi guy amongst the local part
        }
        return st.size();
    }
};