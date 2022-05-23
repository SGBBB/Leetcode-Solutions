class Solution {
public:
    /*
    3 1 2 4
    1 len smaller->1
    
    2 len smaller->1
    3 len smaller->1
    4 len smaller->1
    objective: is to solve this problem in linear time complexity
    
    
    
    */
    int sumSubarrayMins(vector<int>& arr) {
        long long n=arr.size(),cnt=0,mod = 1e9 +7;
        stack<long long> st;
        int left[n],right[n];
        
        for(int i=0;i<n;i++)
            left[i]=-1,right[n-i-1]=n;
        // for(int i=0;i<n;i++)
        //     cout<<left[i]<<" "<<right[i]<<endl;
        
        
        //collecting smaller elements from right side
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) {
                right[st.top()]=i,
                st.pop();
            }
            st.push(i);
        }
        //make st empty
        while(!st.empty())
            st.pop();
        
        //collecting smaller elements from left side
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) {
                left[st.top()]=i,
                st.pop();
            }
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            long long leftSubstrings=i-left[i],
                rightSubstrings=right[i]-i;
            cnt=(cnt+leftSubstrings*rightSubstrings*arr[i]*1LL)%mod;
        }
        return cnt;
        
    }
};