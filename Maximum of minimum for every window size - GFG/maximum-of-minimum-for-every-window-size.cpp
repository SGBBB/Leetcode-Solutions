// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
         stack<int> st;
         //Initially ,Im calculating indices of min guys from both the ends
         vector<int> minLeft(n,-1),minRight(n,n), ans(n+1);
         
         //Calculating min guys from right corrreponding to each guy
         for(auto i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i] ){
                minRight[st.top()]=i,
                st.pop();
            }
            st.push(i);
         } 
         //making stack empty
         while(!st.empty()) st.pop();
        //Calculating min guys from left corrreponding to each guy
         for(auto i=n-1;i>=0;i--){
             while(!st.empty() && arr[st.top()]>arr[i] ){
                minLeft[st.top()]=i,
                st.pop();
            }
            st.push(i);
         }
         //assigning the max values corresponding to every width
         for(int i=0;i<n;i++){
             minLeft[i]++;
             int width=minRight[i]-minLeft[i];
             ans[width]=max(ans[width],arr[i]);
         }
         //just printing vector
        //  for(auto it:ans) cout<<it<<" "; cout<<endl;
         //One obserbvation is that Im sure that largest guy is sitting at first and
        //  smallest guy is sitting at last
         for(int i=n-1;i>0;i--){
             ans[i]=max(ans[i],ans[i+1]);
         }
         ans.erase(ans.begin());
         return ans;
    }
    
    /*
    
    10 20 30 50 10 70 30
    in a window of size k find the minimum and
    out of all minimum determine the maximum guy
    
    70   considering 1 size array
    30   considering 2 size array
    20   considering 3 size array
    10   considering 4 size array
    10   considering 5 size array
    10   considering 6 size array
    10   considering 7 size array
    
    How will I solve thhis problem?????
    10 20 30
    Ans-> 30 20 10
    Hint is that I can make use of stack data structure
    
    Can you print 30 at last?????
    In begining I can put largest guy 
    
    */
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends