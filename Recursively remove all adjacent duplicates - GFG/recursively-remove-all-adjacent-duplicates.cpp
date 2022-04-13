// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string remove(string s ){
        int n=s.size();
        string res="";
        for(int i=0;i<n;) {
             //ignoring duplicates
             
             char ch=s[i];
             int cnt=0;
             while( s[i]==ch ) i++,cnt++;
             if(cnt==1) res+=ch;
        }
        // cout<<s<<" "<<res<<endl;
        if(res==s) return s;
        
        return remove(res);
        
        
    }
};

/*
    abccbccba -> abbba ->aa -> ""
    "geeksforgeek" -> gksforgk 
    Time
*/

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends