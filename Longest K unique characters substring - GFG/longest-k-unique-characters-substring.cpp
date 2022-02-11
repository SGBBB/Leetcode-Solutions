// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    unordered_map<char,int> M;
    int i=0,j=0,n=s.size(),maxLen=-1;
    for(;j<n;j++){ 
        M[s[j]]++;        
         if(M.size()==k){
            maxLen=max(maxLen, j-i+1);
        }
        // else if(M.size()>k){
            while(M.size()>k){
                M[s[i] ]--;
                if(M[s[i] ] ==0) M.erase(s[i] );
                i++;
            }
        // }
                
        
        
    }
    return maxLen;

    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends