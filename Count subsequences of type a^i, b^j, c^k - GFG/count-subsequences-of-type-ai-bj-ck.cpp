// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    
    int fun(string &s) {
        //code here
        int mod=1e9+7;
        int cnt_a=0,cnt_ab=0,cnt_abc=0;
        for(char ch:s){
            
            if(ch=='a'){
                cnt_a=(2*1LL*cnt_a+1)%mod;
            }
            else if(ch=='b'){
                cnt_ab=(2*1LL*cnt_ab+cnt_a)%mod;
            }
            else{
                cnt_abc=(2*1LL*cnt_abc+cnt_ab )%mod;
            }
            
        }
        
        return cnt_abc ;
    }
    
    /*
    abbc
    */
    
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends